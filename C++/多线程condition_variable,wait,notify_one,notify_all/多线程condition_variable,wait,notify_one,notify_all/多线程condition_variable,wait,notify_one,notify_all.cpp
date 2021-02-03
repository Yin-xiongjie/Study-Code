#include <iostream>
#include<thread>
#include<mutex>
#include<list>

using namespace std;
class A
{
public:
	//把收到的消息加入到一个队列的线程
	void inMsgRecvQueue()
	{
		for (int i = 0; i < 100000; i++)
		{
			cout << "inMsgRecvQueue()执行，插入一个元素：" << i << endl;
			std::unique_lock<mutex>guard1(my_mutex1);
			msgRecvQueue.push_back(i);  //假设数字i就是收到的玩家命令。
			//假如outMsgRecvQueue()正在处理一个事务，需要一段时间，而不是正卡在wait()等待唤醒，那么此时这个notify_one()这个调用就没有效果。
			my_condition.notify_one();  //尝试把wait()唤醒，执行完这行，那么outMsgRecvQueue()中的的wait()就被唤醒
										//唤醒之后再做事情
			//.......
			//处理其他代码
		}
		return;
	}

	//bool Lock(int &command)
	//{
	//	//双重锁定，双重检查
	//	if (!msgRecvQueue.empty())
	//	{
	//		unique_lock<mutex>guard1(my_mutex1);
	//		if (!msgRecvQueue.empty())
	//		{
	//			//消息不为空
	//			command = msgRecvQueue.front();  //返回第一个元素
	//			msgRecvQueue.pop_front();        //移除第一个元素，但不返回
	//			return true;
	//		}
	//		return false;
	//	}
	//}

	//把数据从消息队列取出的线程
	void outMsgRecvQueue()
	{

		int command = 0;
		while (true)
		{
			unique_lock<mutex>guard1(my_mutex1);

			//wait()用来等一个东西
			//如果第二个参数lambda表达式返回值是true,那么wait()直接返回；
			//如果第二个参数lambda表达式的返回值是false,那么wait()将解锁互斥量，并堵塞到本行，
			//那堵塞到其他某个线程调用notify_one()成员函数为止；
			//如果没有第二个参数时my_condition.wait(guard1):那么就跟第二个参数lambda表达式返回false表达式一样(也就是wait()将解锁互斥量，并堵塞到本行)。
			//那堵塞到其他某个线程调用notify_one()成员函数为止；
			//当其他线程用notify_one()将本wait()[原本是堵塞状态]唤醒后,wait()就恢复工作
			//wait()不断尝试获取互斥量锁，如果获取不到，那么流程就卡在这儿等着获取，如果获取到了，那么wait()就继续执行
			//获取到了锁过后就等于上了锁

			my_condition.wait(guard1, [this] {   //一个lambda就是一个可调用对象（函数）
				if (!msgRecvQueue.empty())
					return true;
				return false;
			});
			//流程走到这儿，那么互斥锁一定锁着的,同时msgRecvQueue至少是有一条数据的
			command = msgRecvQueue.front();  //返回第一个元素
			msgRecvQueue.pop_front();        //移除第一个元素，但不返回
			cout << "outMsgRecvQueue()执行，取出一个元素" << command<< "this_thread="<<this_thread::get_id()<< endl;
			guard1.unlock();               //因为unique_lock的灵活性，所以可以随时的unlock解锁，以免锁住太久
			//执行一些其他操作
			//假如
		}

		
		/*for (int i = 0; i < 100000; i++)
		{
			bool result = Lock(command);
			if (result == true)
			{
				cout << "outMsgRecvQueue()执行，取出一个元素：" << command << endl;
			}
			else
			{
				printf("消息队列第%d为空\n", i);
			}
		}
		cout << "消息队列处理结束" << endl;*/
	}
private:
	list<int>msgRecvQueue;  //容器，专门用用于代表玩家发送过来的命令。
	mutex my_mutex1;         //创建一个互斥量
	std::condition_variable my_condition; //生成一个我的条件变量对象
};
int main()
{
//一.条件变量std::condition_variable、wait()、notify_one():只能通知一个线程
//线程A:等待一个条件满足
//线程B：专门往线程中扔消息(数据)
//std::condition_variable实际上是一个类，是一个和条件相关的类，其实就是等待条件达成。
//这个类需要和互斥量配合工作；用的时候要生成类的对象

/************************************************************************************/
//二.上述代码的深入思考
//注意这些函数调用的实际场景，应用时要考虑效率，资源等问题

/************************************************************************************/
//三.noify_all()
//
	A myobja;
	thread myOutMesgObj(&A::outMsgRecvQueue, &myobja);
	thread myOutMesgObj2(&A::outMsgRecvQueue, &myobja);
	thread myInMesgObj(&A::inMsgRecvQueue, &myobja);
	myOutMesgObj.join();
	myOutMesgObj2.join();
	myInMesgObj.join();
	return 0;
}


