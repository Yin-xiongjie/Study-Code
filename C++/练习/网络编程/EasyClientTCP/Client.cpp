#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<windows.h>
#include<WinSock2.h>
#include <iostream>
#include<stdio.h>

using namespace std;
//#pragma comment(lib,"ws2_32.lib")

enum CMD
{
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_ERROR
};
//定义一个包头
struct DataHeader
{
	short dataLength; // 数据长度
	short cmd;//命令
};

struct Login :public DataHeader
{
	Login()
	{
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char userName[32];
	char passWord[32];
};

struct LoginResult :public DataHeader
{
	LoginResult()
	{
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
		result = 0;
	}
	int result;
};
struct Logout :public DataHeader
{
	Logout()
	{
		dataLength = sizeof(Logout);
		cmd = CMD_LOGOUT;
	}
	char userName[32];
};
struct LogoutResult :public DataHeader
{
	LogoutResult()
	{
		dataLength = sizeof(LogoutResult);
		cmd = CMD_LOGOUT_RESULT;
		result = 0;
	}
	int result;
};
struct Datapakage
{
	int age;
	char name[32];
};

int main()
{
	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	//用socketAPI建立简易TCP客户端
	//1.建立socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == INVALID_SOCKET)
	{
		printf("Client1建立套节字socket失败！\n");
	}
	else
		printf("Client1建立套节字socket成功！\n");

	//2.连接服务器connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;  //指明创建的是IPV4类型
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int ref = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (ref == SOCKET_ERROR)
	{
		printf("Client1连接服务器失败！\n");
	}
	else
		printf("Client1连接服务器成功！\n");
	while (true)
	{
		//3.输入请求命令
		char cmdBuf[128] = {};
		scanf("%s", &cmdBuf);
		//4.处理请求命令
		if (0 == strcmp(cmdBuf, "exit"))
		{
			printf("服务端1收到exit命令，已退出\n");
			break;
		}
		else if (0 == strcmp(cmdBuf, "login")) {
			//5.向服务器发送请求
			Login login;
			strcpy(login.userName, "yxj");
			strcpy(login.passWord, "YXJmima");
			send(_sock, (const char*)&login, sizeof(login), 0);
			//6.接受服务器返回数据
			LoginResult loginRet = {};
			recv(_sock, (char*)&loginRet, sizeof(loginRet), 0);
			printf("LoginResult: %d\n", loginRet.result);
		}
		else if (0 == strcmp(cmdBuf, "logout")) {
			Logout logout;
			strcpy(logout.userName, "yxj");
			//5.向服务器发送请求
			send(_sock, (const char*)&logout, sizeof(logout), 0);
			//6.接受服务器返回数据
			LoginResult logoutRet = {};
			recv(_sock, (char*)&logoutRet, sizeof(logoutRet), 0);
			printf("LogoutResult: %d\n", logoutRet.result);
		}
		else {
			printf("不支持该命令,请重新输入指令。\n");
		}
	}
	//7.关闭套节字
	closesocket(_sock);
	//关闭Windows socket环境
	WSACleanup();
	printf("服务端1结束任务，已退出\n");
	system("pause");
	return 0;
}

