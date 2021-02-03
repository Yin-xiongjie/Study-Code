#include<iostream>
#include<cmutex>
#include<list>
#include<thread>
#include<ctime>

using namespace std;
long sum = 0;
class A
{
public:
	void InmesgQueue()
	{
		int M_money;
		srand(time(NULL));
		for(int i = 0; i < 10; i++)
		{
			M_money = rand();
			sum+= M_money;
			cout<<"玩家"<<i<<"充值了"<<M_money<<"元"<<endl;
			lock_guard<mutex>guard1(my_mutex1);
			lock_guard<mutex>guard2(my_mutex2);
			chrono::milliseconds S_sleep(2000);
			this_thread::sleep_for(S_sleep);
			mesgRecvQueue.push_back(M_money);
		}
	}
	bool Lock(int &command)
	{
		my_mutex2.lock();
		my_mutex1.lock();
		chrono::milliseconds S_sleep(2000);
		this_thread::sleep_for(S_sleep);
		if(!mesgRecvQueue.empty())
		{
			command = mesgRecvQueue;.front; //返回前一个元素
			mesgRecvQueue.pop+front();     //移除前一个元素
			my_mutex1.unlock();
			my_mutex2.unlock();
			return true;
		}
		my_mutex1.unlock();
		my_mutex2.unlock();
	}
	void outmesgRecQue()
	{
		int command = 0;
		for(int i = 0; i < 10; i++)
		{
			bool result = Lock(command);
			if(result == true)
			{
				cout<<"玩家"<<i-1<<"充值完成"<<command<<"元"<<endl;
			}
			else
			{
				printf("充值队列第%d为空\n\n",i);
			}
		}
		cout<<"充值处理完成!"<<endl;
	}

private:
	list<int>mesgRecvQueue;
	mutex my_mutex1;
	mutex my_mutex2;
} 

int main()
{
	A List;
	thread myoutMeasg(&A::outmesgRecQue,&List);
	thread myoutMeasg(&A::InmesgQueue,&List);
	myoutMeasg.join();
	myoutMeasg.join();
	cout<<"玩家一共充值；"<<sum<<"元"<<endl;
	return;
}