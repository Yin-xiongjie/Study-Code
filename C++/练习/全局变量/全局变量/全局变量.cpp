// 全局变量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include <iostream>
#include<windows.h>

using namespace std;

//通过全局变量进行通信, 要对该变量加关键字volatile
volatile int signalNum = 0;  //volatile(易变的)：每次从内存中去读这个值，而不是因编译器优化从缓存的的地方去读取

//在win32中有这样的定义：
//#define DWORD unsigned long表示一个32位无符号整形数，或用来表示段地址和段地址得偏移量；
//windows下经常用来保存地址（或存放指针），添加时要添加#include<windows.h>
DWORD WINAPI  threadFuncA(LPVOID lpParamter)
{
	Sleep(2000);
	if (0 == signalNum)
	{
		printf("signalNum not changed!\n");
	}
	else
		printf("signalNum has changed\n");
	return 0;
}

DWORD WINAPI threadFuncB(LPVOID lpParamter)
{
	signalNum = 2;
	return 0;
}

int main()
{
	HANDLE threadA = CreateThread(
		NULL,//表示线程内核对象的安全属性；
		0,//表示线程堆栈空间的大小；
		threadFuncA,//表示新线程所执行的线程函数地址
		NULL,//函数的参数
		0,//立即执行
		NULL//返回线程的ID号
		);
	HANDLE threadB = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);

	WaitForSingleObject(threadA, INFINITE);//WaitForSingleObject函数是等待一个线程指定时间，第一个参数是需要等待的目的线程，第二个参数是等待的时间、
	CloseHandle(threadA);//CloseHandle只是关闭了系统句柄，该线程还可以正常的运行。
	CloseHandle(threadB);

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
