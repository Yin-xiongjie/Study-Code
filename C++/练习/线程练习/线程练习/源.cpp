#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>
#include<ctime>
using namespace std;

long sum = 0;

class A
{
public:
	//把收到的消息加入到一个队列的线程
		void inMsgRecvQueue()
		{
			int M_money;
			srand(time(NULL));
			//srand(time(NULL));
			for(int i = 0; i < 10; i++)
			{
				M_money = rand();
				sum+=M_money;
				cout<<"玩家"<<i<<"充值了："<<M_money<<endl;
				lock_guard<mutex>guard1(my_mutex1);
				lock_guard<mutex>guard1(my_mutex2);		
				chrono::milliseconds S_sleep(2000);
				this_thread::sleep_for(S_sleep);//让程序暂停2s
				msgRecvQueue.push_back(M_money);  //M_money是玩家充值的金额。
			}
		}
		bool Lock(int &command)
		{
	
			my_mutex2.lock();
			my_mutex1.lock();
			chrono::milliseconds S_sleep(2000);
			this_thread::sleep_for(S_sleep);//让程序暂停2s
			if(!msgRecvQueue.empty())
			{
				command = msgRecvQueue.front();  //返回第一个元素
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
			for(int i = 0; i < 10; i++)
			{
				bool result = Lock(command);
				if(result == true)
				{
					cout<<"玩家"<<i-1<<"充值完成，充值成功："<<command<<"元"<<'\n'<<endl;
				}
				else
				{
					printf("充值队列第%d为空\n\n", i);
				}
			}
			cout<<"充值信息处理结束!"<<endl;
		}

private:
		list<int>msgRecvQueue;  //创建容器专门用于代表玩家发送过来的命令。
		mutex my_mutex1;         //创建一个互斥量
		mutex my_mutex2;         //创建另一个一个互斥量
};

	
int main()
{
	A List;
	thread myoutMesgobj(&A::outMsgRecvQueue,&List); //第二个参数是引用,才能保证线程里运用的同一个对象
	thread myinMesgobj(&A::inMsgRecvQueue,&List);  //第二个参数是引用,才能保证线程里运用的同一个对象
	myinMesgobj.join();
	myoutMesgobj.join();
	cout<<"所有玩家今日累计充值："<<sum<<"元"<<endl;
	return 0;
}

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//void Fun_1();          //声明分支线程函数Fun_1()
//void Fun_2();          //声明分支线程函数Fun_2()
//
//unsigned int counter = 0;      //定义变量counter，通过变量counter的变化来观察线程同步情况
//std::mutex mtx;           //定义mutex类的对象mtx构造互斥元，互斥占有一个变量，一段时间内仅一个线程可以访问
//
//int main()
//{
//    std::thread thrd_1(Fun_1);     //创建线程thrd_1，thrd_1调用函数Fun_1
//    std::thread thrd_2(Fun_2);     //创建线程thrd_2，thrd_2调用函数Fun_2
//    thrd_1.join();        //join()函数启动子线程而阻塞主线程，子线程会按照开启的先后顺序同步运行，当子线程运行结束后，才会继续运行主线程
//    thrd_2.join();        //启动线程thrd_2,并且阻塞主线程，等到线程thrd_2运行结束后，再继续运行主线程；
//    cout<<"counter= "<< counter <<endl;
//    return 0;
//}
//
//void Fun_1()
//{
//    while (true)
//    {
//     /*std::lock_guard类模板,用于自动锁定解锁，直到对象作用域结束。在 lock_guard 对象构造时，传入的mutex对象 mtx 会被当前线程锁住。在lock_guard 对象被析构时，它所管理的mutex对象mtx会自动解锁*/
//        std::lock_guard<std::mutex> mtx_locker(mtx);    
//        counter++;
//        if (counter < 20)
//		{
//			
//            cout << "线程1有动作了!  counter=" << counter << endl;
//			cout<<"线程地址1："<<this_thread::get_id<<endl;
//		}
//        else
//            break;
//    }
//}
//
//void Fun_2()
//{
//    while (true)
//    {
//     /*std::lock_guard类模板,用于自动锁定解锁，直到对象作用域结束。在 lock_guard 对象构造时，传入的mutex对象 mtx 会被当前线程锁住。在lock_guard 对象被析构时，它所管理的mutex对象mtx会自动解锁*/
//        std::lock_guard<std::mutex> mtx_locker(mtx);   
//        counter++;
//        if (counter < 20)
//		{
//            cout << "线程2有动作了!  counter=" << counter << endl;
//			cout<<"线程地址2："<<this_thread::get_id<<endl;
//		}
//        else
//            break;
//    }
//}