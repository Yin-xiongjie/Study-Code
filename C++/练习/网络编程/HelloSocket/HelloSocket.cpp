#define WIN32_LEAN_AND_MEAN
//#include<WinSock2.h>
#include<windows.h>
#include<WinSock2.h>
#include <iostream>

//#pragma comment(lib,"ws2_32.lib")
int main()
{
	//启动Windows socket 3.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	
	//清除Windows Socket环境
	WSACleanup();
	return 0;

}

