#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>
using namespace std;


class A
{
public:
	//���յ�����Ϣ���뵽һ�����е��߳�
	void inMsgRecvQueue()
	{
		for(int i = 0; i < 100000; i++)
		{
			cout<<"inMsgRecvQueue()ִ�У�����һ��Ԫ�أ�"<<i<<endl;
			//lock_guard<mutex>guard1(my_mutex1);	
		
			//unique_lock<mutex>guard1(my_mutex1,try_to_lock);
			//if(guard1.owns_lock())
			//{
			//unique_lock<mutex>guard1(my_mutex1, defer_lock);  //û�м�����my_mutex1
			unique_lock<mutex>guard1(my_mutex1);
			mutex *ptx = guard1.release();  //����ptx���൱��my_mutex1,ֻ���������ָ�룬��unique_lock��mutex�����й�ϵ������Ҫunlockptx;
			/*if (guard1.try_lock() == true)
			{
				cout << "���Լ����ɹ���" << endl;
			}
			else
				cout << "���Լ���ʧ��" << endl;*/
			//guard1.lock(); //��unique_lock���������õ��Ľ�����
		   	msgRecvQueue.push_back(i);  //��������i�����յ���������
			//}
			//else
			//{
			//	cout<<"����ʧ��"<<endl;
			//}
			ptx->unlock();
		}
	}
bool Lock(int &command)
{
	//lock_guard<mutex>guard1(my_mutex1);  //Guard��һ���Զ�����������,my_mutex��˽�г�Ա�Ļ������βΡ�
	unique_lock<mutex>guard1(my_mutex1); 
									   //lock_guard���캯����ִ����mutex.lock(),��������ִ����mutex.unlock();
	chrono::milliseconds S_sleep(1000);//�ó����������Ϣ1s
	this_thread::sleep_for(S_sleep);//��Ϣ1s
	if(!msgRecvQueue.empty())
	{
		command = msgRecvQueue.front();  //���ص�һ��Ԫ��
		msgRecvQueue.pop_front();        //�Ƴ���һ��Ԫ�أ���������
		return true;
	}
	return false;
}
//�����ݴ���Ϣ����ȡ�����߳�
void outMsgRecvQueue()
{
	int command = 0;
	for(int i = 0; i < 100000; i++)
	{
		bool result = Lock(command);
		if(result == true)
		{
			cout<<"outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ�أ�"<<command<<endl;
		}
		else
		{
			printf("��Ϣ���е�%dΪ��\n", i);
		}
	}
	cout<<"��Ϣ���д������"<<endl;
}
private:
		list<int>msgRecvQueue;  //������ר�������ڴ�����ҷ��͹��������
		mutex my_mutex1;         //����һ��������
};

int main()
{
	A myobja;
	thread myoutMesgobj(&A::outMsgRecvQueue,&myobja); //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	thread myinMesgobj(&A::inMsgRecvQueue,&myobja);  //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	myinMesgobj.join();
	myoutMesgobj.join();
	return 0;
}

//һ. unique_lockȡ��lock_guard
//unique_lock��һ����ģ�壬һ����lock_guard
//unique_guard��lock_guard��Ч�ʵ�һ�㣬ռ���ڴ��һ��
//��.unique_lock�ĵڶ�������
//std::adopt-lock,��ʾ����������Ѿ���lock�ˣ�ֻ����һ��������ã�����ѻ�������ǰlock�ˣ�����ᱨ�쳣,��˱����Ȱѣ�

//��.unique_lock�ĳ�Ա����
//std::lock()����
//std::unlock()����
//std::try_to_lock
//���ǻ᳢����mutex��lock(0ȥ�������mutex�������û�������ɹ���Ҳ���������أ�����������������) 
//��try_to_lock��ǰ����û����ǰȥlock,����ǰlock�ᵼ�³�����������;

//std::defer_lock
//�������ǰ����û����ǰȥlock,�����쳣��
//defer_lock����˼���ǲ�û�и�mutex��������ʼ����һ��û�м�����mutex��
//���ǽ���defer_lock�Ļ��⣬������һЩunique_lock����Ҫ��Ա������

//unique_lock�ĳ�Ա����
//(1)lock(),����
//(2)unlock()������
//(3)try_lock()�����Ը�����������������ò��������򷵻�false,����õ������ͷ���true�����������������
//(4)relese();�������������mutex����ָ�룬���ͷ�����Ȩ��Ҳ����˵unique_lock��mutex�����й�ϵ��ע������unlock()��relese()������
//���ԭ����mutex�����ڼ���״̬���������νӹܹ���������(relese���ص���ԭʼmutex��ָ��)
//�ڱ��ʱҪ��������lock()��unlock()�������Ա�����ƿش�������ȣ��Ӷ�ʹ�����Ч�����С�


//��.unique_lock����Ȩ�Ĵ���mutex,
//std::unique_lock<std::mutex> sbguard1(my_mutex1);����Ȩ����
//sbguard1ӵ��my_mutex1������Ȩ
//sbguard1���԰��Լ���mutex(my_mutex1)������Ȩת�Ƹ�������unique_lock����
//���ԣ�unique_lock�������mutex������Ȩ�ǿ���ת�Ƶģ��������Ը��ơ�
//ת�Ʒ���
//std::unique_lock<std::mutex> sbguard1(my_mutex1);
//std::unique_lock<std::mutex> sbguard2(std::move(sbguard1));//ʹ��move�ƶ����彫sbguard2��mutex1��һ��
															 //����sbguard1�Ѿ�Ϊ�գ�sbguard2�Ѿ��ӹ���my_mutex1;