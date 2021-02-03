#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>
using namespace std;


class A
{
public:
	//把收到的消息加入到一个队列的线程
		void inMsgRecvQueue()
		{
			for(int i = 0; i < 100000; i++)
			{
				cout<<"inMsgRecvQueue执行，插入一个元素："<<i<<endl;
				lock(my_mutex1,my_mutex2);
				lock_guard<mutex>guard1(my_mutex1,adopt_lock);
				lock_guard<mutex>guard2(my_mutex2,adopt_lock);
				//lock_guard<mutex>guard(my_mutex2,adopt_lock);
				//my_mutex1.lock();
				////....内容代码....
				//my_mutex2.lock();
				msgRecvQueue.push_back(i);  //假设数字i就是收到的玩家命令。
			/*	my_mutex2.unlock();
				my_mutex1.unlock();*/
			}
		}
bool Lock(int &command)
{
	//lock_guard<mutex>guard(my_mutex1);  //Guard是一个自定义的类对象名,my_mutex是私有成员的互斥量形参。
									   //lock_guard构造函数里执行了mutex.lock(),析构函数执行了mutex.unlock();
	my_mutex2.lock();
	my_mutex1.lock();
	//lock(my_mutex1,my_mutex2);
	if(!msgRecvQueue.empty())
	{
		int command = msgRecvQueue.front();  //返回第一个元素
		msgRecvQueue.pop_front();        //移除第一个元素，但不返回
		my_mutex1.unlock();
		my_mutex2.unlock();
		return true;
	}
	my_mutex1.unlock();
	my_mutex2.unlock();
	return false;
}
//把数据从消息队列取出的线程
void outMsgRecvQueue()
{
	int command = 0;
	for(int i = 0; i < 100000; i++)
	{
		bool result = Lock(command);
		if(result == true)
		{
			cout<<"outMsgRecvQueue()执行，取出一个元素"<<command<<endl;
		}
		else
		{
			printf("消息队列第%d为空\n", i);
		}
	}
	cout<<"消息队列处理结束"<<endl;
}
private:
		list<int>msgRecvQueue;  //容器，专门用用于代表玩家发送过来的命令。
		mutex my_mutex1;         //创建一个互斥量
		mutex my_mutex2;         //创建另一个一个互斥量
};


//线程入口函数
//void myprint(int inum)
//{
//	cout<<"我的线程开始执行,编号为："<<inum<<endl;
//	//...
//	//...
//	cout<<"我的线程结束,编号为"<<inum<<endl;
//}
int main()
{
	////一，创建和等待多个线程
	////创建多个线程  把thread放到容器里，类似线程数组，这种方法可以一次创建多个线程
	//vector<thread>mythreads;
	////创建10个线程，全为myprint
	//for(int i = 0; i < 10; i++)
	//{
	//	mythreads.push_back(thread(myprint,i));//创建并开始执行线程
	//}
	//for(auto iter = mythreads.begin();iter != mythreads.end();++iter)
	//{
	//	iter->join();  //等待10个线程结束
	//}
	//cout<<"I Like c++"<<endl;

	//二.数据共享问题分析
	//2.1只读的数据：是安全稳定的，不需要特别的处理手段，直接读就行。
	//2.2有读有写：2个线程写，8个线程读，因此代码必须处理，否则崩溃，最简单的处理就是读的时候不写，写的时候不写，2个线程不同时写，8个线程不同时写；
	//若不分开进行，程序写和读乱套，程序崩溃。

	//三。共享数据的保护案例
	//网络服务器。两个自己创建的线程，一个线程收集玩家命令，并把命令数据写进队列中。
	//另一个线程从队列中取出玩家发来的命令，解析然后执行玩家需要的动作。
	//vector,list类似，但是内部实现手段不一样，list在频繁的按顺序插入删除数据时效率高，vector随机的删除，插入数据效率更高。

	//准备用成员函数作为线程函数的方法来写线程；
	A myobja;
	thread myoutMesgobj(&A::outMsgRecvQueue,&myobja); //第二个参数是引用,才能保证线程里运用的同一个对象
	thread myinMesgobj(&A::inMsgRecvQueue,&myobja);  //第二个参数是引用,才能保证线程里运用的同一个对象
	myinMesgobj.join();
	myoutMesgobj.join();
	return 0;
}
//********************解决多线程数据共享问题的第一个概念---------“互斥量”-----------**************************
//保护共享数据，某个线程操作共享数据时，用代码将共享数据锁住，操作数据，其他需要操作共享数据的线程必须等待解锁；
//互斥量（mutex）的概念
//互斥量是个类对象。就像一把锁，多个线程尝试用lock()成员函数加锁，只有一个线程可以锁定成功（成功的标志是lock函数返回）
//如果没有锁成功，那么程序卡在lock这儿不断地尝试去解锁。
//使用互斥量要注意保护的位置，保护多影响效率，少了没达到保护的效果。

//二.互斥量的用法
//lock()和unlock()
//先lock()，操作共享数据，操作完了unlock()
//lock,ulock成对使用。若不成对使用则代码崩溃。
//为了防止忘记unlock(),引入了一个lock-guard的类模板，直接取代lock()和unlock(),使用了lock_guard后就不能使用lock()和unlock()了。

//三.死锁
//c++中，死锁这个问题至少要两个互斥量（也就是两个锁头）才能产生；假设有两把锁 A锁（ALock）B锁（BLock）
//两个线程A,B;
//(1)线程A执行的时候，这个线程先锁A锁，把A锁(ALock)锁成功了，然后再去尝试LockB锁(BLock)
//线程A还没有将B锁锁成功，就将线程切换到B
//(2)线程B开始执行，这个线程先锁B锁，因为B锁还没有被锁，所以B锁会Lock成功，线程B又去尝试LockA锁。
//这种情况下死锁发生，线程A锁住A锁，尝试锁B锁，线程B锁住B锁，尝试锁A锁，因此线程A拿不到B锁，线程B拿不到A锁，因此都锁在这儿。

//（3.1)死锁演示
//(3.2)死锁的解决方法
//保证两个互斥量上锁顺序一样
//(3.3)std::lock()函数模板 std::lock(my_mutex1,my_mutex2);
//作用：一次锁住多个互斥量（至少两个），处理多个互斥量；
//不存在因为锁的顺序问题而造成的死锁问题，如果互斥量中有一个没有锁住，就把前面锁住的释放掉，以免影响其他进程加锁，当这些能同时锁住时再锁，再继续往下。
//总结特点就是要么同时锁住，要么都锁不住。
//(3.4)std::lock_guard的std::adopt lock参数。