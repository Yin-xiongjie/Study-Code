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
			cout<<"inMsgRecvQueue()执行，插入一个元素："<<i<<endl;
			//lock_guard<mutex>guard1(my_mutex1);	
		
			//unique_lock<mutex>guard1(my_mutex1,try_to_lock);
			//if(guard1.owns_lock())
			//{
			//unique_lock<mutex>guard1(my_mutex1, defer_lock);  //没有加锁的my_mutex1
			unique_lock<mutex>guard1(my_mutex1);
			mutex *ptx = guard1.release();  //现在ptx就相当于my_mutex1,只不过变成了指针，因unique_lock和mutex不再有关系，所以要unlockptx;
			/*if (guard1.try_lock() == true)
			{
				cout << "尝试加锁成功！" << endl;
			}
			else
				cout << "尝试加锁失败" << endl;*/
			//guard1.lock(); //给unique_lock加锁，不用担心解锁。
		   	msgRecvQueue.push_back(i);  //假设数字i就是收到的玩家命令。
			//}
			//else
			//{
			//	cout<<"加锁失败"<<endl;
			//}
			ptx->unlock();
		}
	}
bool Lock(int &command)
{
	//lock_guard<mutex>guard1(my_mutex1);  //Guard是一个自定义的类对象名,my_mutex是私有成员的互斥量形参。
	unique_lock<mutex>guard1(my_mutex1); 
									   //lock_guard构造函数里执行了mutex.lock(),析构函数执行了mutex.unlock();
	chrono::milliseconds S_sleep(1000);//让程序在这儿休息1s
	this_thread::sleep_for(S_sleep);//休息1s
	if(!msgRecvQueue.empty())
	{
		command = msgRecvQueue.front();  //返回第一个元素
		msgRecvQueue.pop_front();        //移除第一个元素，但不返回
		return true;
	}
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
			cout<<"outMsgRecvQueue()执行，取出一个元素："<<command<<endl;
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
};

int main()
{
	A myobja;
	thread myoutMesgobj(&A::outMsgRecvQueue,&myobja); //第二个参数是引用,才能保证线程里运用的同一个对象
	thread myinMesgobj(&A::inMsgRecvQueue,&myobja);  //第二个参数是引用,才能保证线程里运用的同一个对象
	myinMesgobj.join();
	myoutMesgobj.join();
	return 0;
}

//一. unique_lock取代lock_guard
//unique_lock是一个类模板，一般用lock_guard
//unique_guard比lock_guard灵活，效率低一点，占用内存多一点
//二.unique_lock的第二个参数
//std::adopt-lock,表示这个互斥量已经被lock了，只是起一个标记作用（必须把互斥量提前lock了，否则会报异常,因此必须先把）

//三.unique_lock的成员函数
//std::lock()加锁
//std::unlock()解锁
//std::try_to_lock
//我们会尝试用mutex的lock(0去锁定这个mutex，但如果没有锁定成功，也会立即返回，并不会阻塞在那里) 
//用try_to_lock的前提是没有提前去lock,若提前lock会导致程序卡死在这里;

//std::defer_lock
//用这个的前提是没有提前去lock,否则报异常。
//defer_lock的意思就是并没有给mutex加锁，初始化了一个没有加锁的mutex，
//我们借用defer_lock的话题，来介绍一些unique_lock的重要成员函数。

//unique_lock的成员函数
//(1)lock(),加锁
//(2)unlock()，解锁
//(3)try_lock()，尝试给互斥量加锁，如果拿不到锁，则返回false,如果拿到了锁就返回true，这个函数不阻塞。
//(4)relese();返回他所管理的mutex对象指针，并释放所有权；也就是说unique_lock和mutex不再有关系；注意区分unlock()和relese()的区别。
//如果原来的mutex对象处于加锁状态，你有责任接管过来并解锁(relese返回的是原始mutex的指针)
//在编程时要合理运用lock()和unlock()函数，以便合理掌控代码的粒度，从而使程序高效的运行。


//四.unique_lock所有权的传递mutex,
//std::unique_lock<std::mutex> sbguard1(my_mutex1);所有权概念
//sbguard1拥有my_mutex1的所有权
//sbguard1可以把自己对mutex(my_mutex1)的所有权转移给其他的unique_lock对象；
//所以，unique_lock对象这个mutex的所有权是可以转移的，但不可以复制。
//转移方法
//std::unique_lock<std::mutex> sbguard1(my_mutex1);
//std::unique_lock<std::mutex> sbguard2(std::move(sbguard1));//使用move移动语义将sbguard2和mutex1绑到一起。
															 //现在sbguard1已经为空，sbguard2已经接管了my_mutex1;