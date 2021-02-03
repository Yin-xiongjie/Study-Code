// 自开线程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
#include<thread>  
#include<mutex>
#include<windows.h>
using namespace std;

//创建一个类对象
class MyClass
{
public:
	void Operator(int a1, int a2)
	{
		cout << "类对象线程入口函数创建成功！"<<a1+a2 << endl;
	}
	

private:

};

//创建一个线程入口函数
void  Function(int a1, double a2)
{
	cout << "函数入口函数创建成功：" << (double)a1 + a2 << endl;
}

DWORD WINAPI Threadfunc(LPVOID ptr_1)
{
	printf("使用Creat Thread 开线程成功！\n");
	cout <<ptr_1<< endl;
	return 0;
}

int main()
{
	//1.使用类对象开启线程
	MyClass ClassA;
	thread Func1(&MyClass::Operator, &ClassA,4, 9);
	Func1.join();
	thread Func2(Function,6,7.3);
	Func2.join();
	int prama = 30;
 	HANDLE handle = CreateThread(NULL, 0, Threadfunc,&prama, 0, NULL);
	WaitForSingleObject(Threadfunc, INFINITE);
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
