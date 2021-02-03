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
				cout<<"inMsgRecvQueueִ�У�����һ��Ԫ�أ�"<<i<<endl;
				lock(my_mutex1,my_mutex2);
				lock_guard<mutex>guard1(my_mutex1,adopt_lock);
				lock_guard<mutex>guard2(my_mutex2,adopt_lock);
				//lock_guard<mutex>guard(my_mutex2,adopt_lock);
				//my_mutex1.lock();
				////....���ݴ���....
				//my_mutex2.lock();
				msgRecvQueue.push_back(i);  //��������i�����յ���������
			/*	my_mutex2.unlock();
				my_mutex1.unlock();*/
			}
		}
bool Lock(int &command)
{
	//lock_guard<mutex>guard(my_mutex1);  //Guard��һ���Զ�����������,my_mutex��˽�г�Ա�Ļ������βΡ�
									   //lock_guard���캯����ִ����mutex.lock(),��������ִ����mutex.unlock();
	my_mutex2.lock();
	my_mutex1.lock();
	//lock(my_mutex1,my_mutex2);
	if(!msgRecvQueue.empty())
	{
		int command = msgRecvQueue.front();  //���ص�һ��Ԫ��
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
	for(int i = 0; i < 100000; i++)
	{
		bool result = Lock(command);
		if(result == true)
		{
			cout<<"outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��"<<command<<endl;
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
		mutex my_mutex2;         //������һ��һ��������
};


//�߳���ں���
//void myprint(int inum)
//{
//	cout<<"�ҵ��߳̿�ʼִ��,���Ϊ��"<<inum<<endl;
//	//...
//	//...
//	cout<<"�ҵ��߳̽���,���Ϊ"<<inum<<endl;
//}
int main()
{
	////һ�������͵ȴ�����߳�
	////��������߳�  ��thread�ŵ�����������߳����飬���ַ�������һ�δ�������߳�
	//vector<thread>mythreads;
	////����10���̣߳�ȫΪmyprint
	//for(int i = 0; i < 10; i++)
	//{
	//	mythreads.push_back(thread(myprint,i));//��������ʼִ���߳�
	//}
	//for(auto iter = mythreads.begin();iter != mythreads.end();++iter)
	//{
	//	iter->join();  //�ȴ�10���߳̽���
	//}
	//cout<<"I Like c++"<<endl;

	//��.���ݹ����������
	//2.1ֻ�������ݣ��ǰ�ȫ�ȶ��ģ�����Ҫ�ر�Ĵ����ֶΣ�ֱ�Ӷ����С�
	//2.2�ж���д��2���߳�д��8���̶߳�����˴�����봦�������������򵥵Ĵ�����Ƕ���ʱ��д��д��ʱ��д��2���̲߳�ͬʱд��8���̲߳�ͬʱд��
	//�����ֿ����У�����д�Ͷ����ף����������

	//�����������ݵı�������
	//����������������Լ��������̣߳�һ���߳��ռ�������������������д�������С�
	//��һ���̴߳Ӷ�����ȡ����ҷ������������Ȼ��ִ�������Ҫ�Ķ�����
	//vector,list���ƣ������ڲ�ʵ���ֶβ�һ����list��Ƶ���İ�˳�����ɾ������ʱЧ�ʸߣ�vector�����ɾ������������Ч�ʸ��ߡ�

	//׼���ó�Ա������Ϊ�̺߳����ķ�����д�̣߳�
	A myobja;
	thread myoutMesgobj(&A::outMsgRecvQueue,&myobja); //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	thread myinMesgobj(&A::inMsgRecvQueue,&myobja);  //�ڶ�������������,���ܱ�֤�߳������õ�ͬһ������
	myinMesgobj.join();
	myoutMesgobj.join();
	return 0;
}
//********************������߳����ݹ�������ĵ�һ������---------����������-----------**************************
//�����������ݣ�ĳ���̲߳�����������ʱ���ô��뽫����������ס���������ݣ�������Ҫ�����������ݵ��̱߳���ȴ�������
//��������mutex���ĸ���
//�������Ǹ�����󡣾���һ����������̳߳�����lock()��Ա����������ֻ��һ���߳̿��������ɹ����ɹ��ı�־��lock�������أ�
//���û�����ɹ�����ô������lock������ϵس���ȥ������
//ʹ�û�����Ҫע�Ᵽ����λ�ã�������Ӱ��Ч�ʣ�����û�ﵽ������Ч����

//��.���������÷�
//lock()��unlock()
//��lock()�������������ݣ���������unlock()
//lock,ulock�ɶ�ʹ�á������ɶ�ʹ������������
//Ϊ�˷�ֹ����unlock(),������һ��lock-guard����ģ�壬ֱ��ȡ��lock()��unlock(),ʹ����lock_guard��Ͳ���ʹ��lock()��unlock()�ˡ�

//��.����
//c++�У����������������Ҫ������������Ҳ����������ͷ�����ܲ����������������� A����ALock��B����BLock��
//�����߳�A,B;
//(1)�߳�Aִ�е�ʱ������߳�����A������A��(ALock)���ɹ��ˣ�Ȼ����ȥ����LockB��(BLock)
//�߳�A��û�н�B�����ɹ����ͽ��߳��л���B
//(2)�߳�B��ʼִ�У�����߳�����B������ΪB����û�б���������B����Lock�ɹ����߳�B��ȥ����LockA����
//��������������������߳�A��סA����������B�����߳�B��סB����������A��������߳�A�ò���B�����߳�B�ò���A������˶����������

//��3.1)������ʾ
//(3.2)�����Ľ������
//��֤��������������˳��һ��
//(3.3)std::lock()����ģ�� std::lock(my_mutex1,my_mutex2);
//���ã�һ����ס�������������������������������������
//��������Ϊ����˳���������ɵ��������⣬�������������һ��û����ס���Ͱ�ǰ����ס���ͷŵ�������Ӱ���������̼���������Щ��ͬʱ��סʱ�������ټ������¡�
//�ܽ��ص����Ҫôͬʱ��ס��Ҫô������ס��
//(3.4)std::lock_guard��std::adopt lock������