#include<iostream>
#include<thread> //�̱߳�׼��
#include<string>
using namespace std;

//void func()   //�������߳�
//{
//	cout<<"�ҵ��߳̿�ʼִ��1"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��2"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��3"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��4"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��5"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��6"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��7"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��8"<<endl;
//	cout<<"�ҵ��߳̿�ʼִ��9"<<endl;
//}

//����һ����
class TA  //�����治Ҫ�����ã����׳���δ֪�Ĵ���  
{
public:
	int m_i;
	TA(int i): m_i(i)  //���캯��,���ι���
	{
		cout<<"TA�������캯����ִ��"<<endl;
	}
	TA(const TA &ta): m_i(ta.m_i)
	{
		cout<<"TA�����������캯��ִ��"<<endl;
	}
	void operator()() //���ܴ�����
	{
		//cout<<"�ҵ��߳̿�ʼִ��"<<endl;
		////...
		////...
		//cout<<"�ҵ��߳̽���ִ����"<<endl;
		cout<<"m_i1��ֵΪ;"<<m_i<<endl;
		cout<<"m_i2��ֵΪ;"<<m_i<<endl;
		cout<<"m_i3��ֵΪ;"<<m_i<<endl;
		cout<<"m_i4��ֵΪ;"<<m_i<<endl;
		cout<<"m_i5��ֵΪ;"<<m_i<<endl;
		cout<<"m_i6��ֵΪ;"<<m_i<<endl;
		
	}
	~TA()
	{
		cout<<"TA()����������ִ��"<<endl;
	}
};
int main()
{
//1��һ��ʹ�ú�����������
	//thread th(func);  //�������߳���ڣ��߳�ִ����㡣
	//if(th.joinable())
	//{
	//	cout<<"joinable == true,���߳�ִ�гɹ�"<<endl;
	//	th.join();
	//}
	//else
	//{
	//	printf("joinable == false,���߳�ִ�в��ɹ�\n");
	//}
	////th.join();     //�������̣߳������̵߳ȴ����߳�ִ�����
	////th.detach();     //ʹ���߳������߳�ʧȥ��ϵ������ִ�У������߳���ִ�������߳����ں�ִ̨�У����Ƽ����޷��������̡߳�������detach�Ͳ��ܵ���join�ˡ� 

	////joinable(),�ж��Ƿ�ɹ�ʹ��join()����detach,����true����false.
	//if(th.joinable())��
	//{
	//	cout<<"joinable == true,���߳�ִ�гɹ�"<<endl;
	//}
	//else
	//{
	//	printf("joinable == false,���߳�ִ�в��ɹ�\n");
	//}

	////2.����������һ������󴴽�����
	int myi = 6;
	TA ta(myi);
	thread th(ta); //ta�Ǳ����Ƶ��߳���ȥ������detachʱ����ʹ���߳̽���Ҳ��Ӱ����ִ�У�ִ�������߳�ʱta�ᱻ���٣������Ƶ�ta�Ծɴ��ڡ�
	th.join(); 
	//th.detach();

	//3.��������lambda���ʽ����һ���߳�
	//auto mylamthread =[]{
	//	cout<<"�ҵ��߳�ִ����"<<endl;
	//	//......
	//	//......
	//	cout<<"�ҵ��߳�ִ�н�����"<<endl;
	//};
	//thread th(mylamthread);
	//th.join();
	cout<<"I lOVE C++ 1"<<endl;
	/*cout<<"I lOVE C++ 2"<<endl;
	cout<<"I lOVE C++ 3"<<endl;
	cout<<"I lOVE C++ 4"<<endl;
	cout<<"I lOVE C++ 5"<<endl;*/
}