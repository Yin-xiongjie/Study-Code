#include <iostream>
#include<mutex>
#include<thread>
#include<list>
#include<vector>
#include<chrono>

using namespace std;

std::mutex resouce_mutex;
std::once_flag g_flag;//这是个系统定义的标记

class MyCAS //这是一个单例类
{
	static void CreatInstanse()//只被调用一次
	{
		chrono::milliseconds S_sleep(5000); //休息5秒
		this_thread::sleep_for(S_sleep);
		cout << "CreatInstanse()被执行完毕了" << endl;
		m_instanse = new MyCAS();
		static CGarhuishou c1;
	}
private:
	MyCAS() {} //私有化了构造函数
private:
	static MyCAS *m_instanse; //静态成员变量，创建一个指针（m_instanse）指向My_CAS这个类对象

public:
	static MyCAS *GetInstance()
	{
		//a）如果 if(m_instanse != NULL)条件成立，则肯定表示m_instanse已经被new过了； 
		//a）如果 if(m_instanse == NULL)条件成立，则不代表m_instanse一定被new过了，因为多个线程同时进行时线程之间相互切换
		//if (m_instanse == NULL)//双重检查，提高效率
		//{
		//	unique_lock<mutex>mymutex(resouce_mutex);//自动加锁和解锁
		//	if (m_instanse == NULL)
		//	{
		//		m_instanse = new MyCAS();
		//		static CGarhuishou c1;
		//	}
		//}
		std::call_once(g_flag, CreatInstanse);
		cout << "call_once()执行完毕！" << endl;
		return m_instanse;
	}
	class CGarhuishou//类中套类，用来释放m_instanse对象
	{
	public:
		~CGarhuishou()
		{
			if (MyCAS::m_instanse)
			{
				delete MyCAS::m_instanse;
				MyCAS::m_instanse = NULL;
			}
		}
	};
	void func()
	{
		cout << "测试" << endl;
	}
};

//类静态变量初始化
MyCAS *MyCAS::m_instanse = NULL;

void mythread()
{
	cout << "我的线程开始执行了" << endl;
	MyCAS *p_a = MyCAS::GetInstance();  //这里可能就有问题了
	cout << "我的线程执行完毕了" << endl;
	return;
}
int main()
{
//一,设计模式大概谈
//"设计模式"：代码的一些写法(这些写法跟常规写法不怎么一样):程序灵活，维护起来可能方便，但是别人接管起来和阅读会很难受。
//用设计模式写出来的代码是很晦涩的，<<head first>>
//老外用来应付比较大的项目，把项目的开发按经验，总结整理成——设计模式（先有开发需求，后有理论总结和整理）
//设计模式在中国，不太一样，一个小程序老生搬硬套几个设计模式进去
//设计模式有它的优点，要活学活用，不要生搬硬套。
	//MyCAS a;//无法这样创建类

//**************************************************************************************//
//二，单例设计模式
//单例设计模式，使用频率比较高；
//单例：有某个或者某些特殊的类，属于该类的对象，我只能创建一个，多了就创建不了；
//单例类:
	//MyCAS *p_a = MyCAS::GetInstance();//创建一个单例类对象，返回该类对象的指针；
	//MyCAS *p_b = MyCAS::GetInstance();
	//p_a->func();
	//p_b->func();
	//MyCAS::GetInstance()->func();

//***************************************************************************************//
//三.单例设计模式共享数据问题分析，解决
//面临的问题：需要在我们自己创建的线程(而不是主线程)中创建MyCAS这个单例类对象，这种线程可能不止一个(最少两个)
//我们可能面临GetInstanse()这种成员函数互斥；

//如下：虽然这两个线程是同一个入口函数，但这是两个线程，所以这里两条通路同时执行mythread这个函数
	thread  mytobj1(mythread);
	thread  mytobj2(mythread);
	mytobj1.join();
	mytobj2.join();

//************************************************************************************************//
//四.std::call_once() c++11引入的函数,该函数的第二个函数是一个函数名a();
//call_once()的功能是保证函数a()只被调用一次，
//具备互斥量这种能力，而且效率上，比互斥量消耗的资源更少；
//call_once()需要与一个标记结合使用，这个标记是std::once_flag;其是once_flag就是一个结构；
//call_once()就是通过这个标记来决定对应函数a()是否执行，调用call_once()成功后11，call_once()就把这个标记设置为一种已调用状态；
//后续再调用call_once(），只要once_flag被设置为"已调用状态"，那么对应的函数a()就不会在执行了；
	return 0;
}

