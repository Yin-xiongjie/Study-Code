#include<iostream>
#include<thread> //线程标准库
#include<string>
using namespace std;

//void func()   //创建子线程
//{
//	cout<<"我的线程开始执行1"<<endl;
//	cout<<"我的线程开始执行2"<<endl;
//	cout<<"我的线程开始执行3"<<endl;
//	cout<<"我的线程开始执行4"<<endl;
//	cout<<"我的线程开始执行5"<<endl;
//	cout<<"我的线程开始执行6"<<endl;
//	cout<<"我的线程开始执行7"<<endl;
//	cout<<"我的线程开始执行8"<<endl;
//	cout<<"我的线程开始执行9"<<endl;
//}

//创建一个类
class TA  //类里面不要用引用，容易出现未知的错误  
{
public:
	int m_i;
	TA(int i): m_i(i)  //构造函数,带参构造
	{
		cout<<"TA（）构造函数被执行"<<endl;
	}
	TA(const TA &ta): m_i(ta.m_i)
	{
		cout<<"TA（）拷贝制造函数执行"<<endl;
	}
	void operator()() //不能带参数
	{
		//cout<<"我的线程开始执行"<<endl;
		////...
		////...
		//cout<<"我的线程结束执行了"<<endl;
		cout<<"m_i1的值为;"<<m_i<<endl;
		cout<<"m_i2的值为;"<<m_i<<endl;
		cout<<"m_i3的值为;"<<m_i<<endl;
		cout<<"m_i4的值为;"<<m_i<<endl;
		cout<<"m_i5的值为;"<<m_i<<endl;
		cout<<"m_i6的值为;"<<m_i<<endl;
		
	}
	~TA()
	{
		cout<<"TA()析构函数被执行"<<endl;
	}
};
int main()
{
//1法一，使用函数创建进程
	//thread th(func);  //创建子线程入口，线程执行起点。
	//if(th.joinable())
	//{
	//	cout<<"joinable == true,子线程执行成功"<<endl;
	//	th.join();
	//}
	//else
	//{
	//	printf("joinable == false,子线程执行不成功\n");
	//}
	////th.join();     //阻塞主线程，让主线程等待子线程执行完毕
	////th.detach();     //使子线程与主线程失去联系，各自执行，若主线程先执行完子线程则在后台执行，不推荐，无法控制子线程。调用了detach就不能调用join了。 

	////joinable(),判断是否成功使用join()或者detach,返回true或者false.
	//if(th.joinable())、
	//{
	//	cout<<"joinable == true,子线程执行成功"<<endl;
	//}
	//else
	//{
	//	printf("joinable == false,子线程执行不成功\n");
	//}

	////2.法二，生成一个类对象创建进程
	int myi = 6;
	TA ta(myi);
	thread th(ta); //ta是被复制到线程中去，在用detach时，即使主线程结束也不影响其执行，执行完主线程时ta会被销毁，但复制的ta仍旧存在。
	th.join(); 
	//th.detach();

	//3.法三，用lambda表达式创建一个线程
	//auto mylamthread =[]{
	//	cout<<"我的线程执行了"<<endl;
	//	//......
	//	//......
	//	cout<<"我的线程执行结束了"<<endl;
	//};
	//thread th(mylamthread);
	//th.join();
	cout<<"I lOVE C++ 1"<<endl;
	/*cout<<"I lOVE C++ 2"<<endl;
	cout<<"I lOVE C++ 3"<<endl;
	cout<<"I lOVE C++ 4"<<endl;
	cout<<"I lOVE C++ 5"<<endl;*/
}