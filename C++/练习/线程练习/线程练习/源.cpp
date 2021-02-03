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
	//���յ�����Ϣ���뵽һ�����е��߳�
		void inMsgRecvQueue()
		{
			int M_money;
			srand(time(NULL));
			//srand(time(NULL));
			for(int i = 0; i < 10; i++)
			{
				M_money = rand();
				sum+=M_money;
				cout<<"���"<<i<<"��ֵ�ˣ�"<<M_money<<endl;
				lock_guard<mutex>guard1(my_mutex1);
				lock_guard<mutex>guard1(my_mutex2);		
				chrono::milliseconds S_sleep(2000);
				this_thread::sleep_for(S_sleep);//�ó�����ͣ2s
				msgRecvQueue.push_back(M_money);  //M_money����ҳ�ֵ�Ľ�
			}
		}
		bool Lock(int &command)
		{
	
			my_mutex2.lock();
			my_mutex1.lock();
			chrono::milliseconds S_sleep(2000);
			this_thread::sleep_for(S_sleep);//�ó�����ͣ2s
			if(!msgRecvQueue.empty())
			{
				command = msgRecvQueue.front();  //���ص�һ��Ԫ��
				msgRecvQueue.pop_front();        //�Ƴ���һ��Ԫ�أ���������
				my_mutex1.unlock();
				my_mutex2.unlock();
				return true;
			}
			my_mutex1.unlock();
			my_mutex2.unlock();
			return false;
		}
		//�����ݴ���Ϣ����ȡ�����߳�
		void outMsgRecvQueue()
		{
			int command = 0;
			for(int i = 0; i < 10; i++)
			{
				bool result = Lock(command);
				if(result == true)
				{
					cout<<"���"<<i-1<<"��ֵ��ɣ���ֵ�ɹ���"<<command<<"Ԫ"<<'\n'<<endl;
				}
				else
				{
					printf("��ֵ���е�%dΪ��\n\n", i);
				}
			}
			cout<<"��ֵ��Ϣ�������!"<<endl;
		}

private:
		list<int>msgRecvQueue;  //��������ר�����ڴ�����ҷ��͹��������
		mutex my_mutex1;         //����һ��������
		mutex my_mutex2;         //������һ��һ��������
};

	
int main()
{
	A List;
	thread myoutMesgobj(&A::outMsgRecvQueue,&List); //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	thread myinMesgobj(&A::inMsgRecvQueue,&List);  //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	myinMesgobj.join();
	myoutMesgobj.join();
	cout<<"������ҽ����ۼƳ�ֵ��"<<sum<<"Ԫ"<<endl;
	return 0;
}

//#include <iostream>
//#include <thread>
//#include <mutex>
//using namespace std;
//
//void Fun_1();          //������֧�̺߳���Fun_1()
//void Fun_2();          //������֧�̺߳���Fun_2()
//
//unsigned int counter = 0;      //�������counter��ͨ������counter�ı仯���۲��߳�ͬ�����
//std::mutex mtx;           //����mutex��Ķ���mtx���컥��Ԫ������ռ��һ��������һ��ʱ���ڽ�һ���߳̿��Է���
//
//int main()
//{
//    std::thread thrd_1(Fun_1);     //�����߳�thrd_1��thrd_1���ú���Fun_1
//    std::thread thrd_2(Fun_2);     //�����߳�thrd_2��thrd_2���ú���Fun_2
//    thrd_1.join();        //join()�����������̶߳��������̣߳����̻߳ᰴ�տ������Ⱥ�˳��ͬ�����У������߳����н����󣬲Ż�����������߳�
//    thrd_2.join();        //�����߳�thrd_2,�����������̣߳��ȵ��߳�thrd_2���н������ټ����������̣߳�
//    cout<<"counter= "<< counter <<endl;
//    return 0;
//}
//
//void Fun_1()
//{
//    while (true)
//    {
//     /*std::lock_guard��ģ��,�����Զ�����������ֱ������������������� lock_guard ������ʱ�������mutex���� mtx �ᱻ��ǰ�߳���ס����lock_guard ��������ʱ�����������mutex����mtx���Զ�����*/
//        std::lock_guard<std::mutex> mtx_locker(mtx);    
//        counter++;
//        if (counter < 20)
//		{
//			
//            cout << "�߳�1�ж�����!  counter=" << counter << endl;
//			cout<<"�̵߳�ַ1��"<<this_thread::get_id<<endl;
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
//     /*std::lock_guard��ģ��,�����Զ�����������ֱ������������������� lock_guard ������ʱ�������mutex���� mtx �ᱻ��ǰ�߳���ס����lock_guard ��������ʱ�����������mutex����mtx���Զ�����*/
//        std::lock_guard<std::mutex> mtx_locker(mtx);   
//        counter++;
//        if (counter < 20)
//		{
//            cout << "�߳�2�ж�����!  counter=" << counter << endl;
//			cout<<"�̵߳�ַ2��"<<this_thread::get_id<<endl;
//		}
//        else
//            break;
//    }
//}