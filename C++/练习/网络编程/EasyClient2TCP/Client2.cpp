#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h>
#include<windows.h>

int main()
{
	//启动windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(ver, &data);
	//1.建立socket套节字
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == INVALID_SOCKET)
	{
		printf("Client2建立套节字socket失败！\n");
	}
	else
		printf("Client2建立套节字socket成功！\n");
	//2.连接服务器 Connect
	sockaddr_in _sin{};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("128.10.10.1");
	int ref1 = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ref1)
	{
		printf("Client2连接服务器失败！\n");
	}
	else
		printf("Client2连接服务器成功！\n");
	//3.接收服务器信息recv
	char RecvBuf[256] = {};
	int CLength = recv(_sock, RecvBuf, 256, 0);
	if (CLength > 0)
	{
		printf("Client2接收信息成功！，接收信息为：%s\n", RecvBuf);
	}
	else
		printf("Client2接收信息失败\n");
	//4.关闭套节字
	closesocket(_sock);
	//关闭socket环境
	WSACleanup();
	system("pause");
	return 0;
}