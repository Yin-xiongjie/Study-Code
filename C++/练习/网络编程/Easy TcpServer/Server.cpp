#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
//#include<WinSock2.h>
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
		cmd = CMD_LOGIN_RESULT;
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
	//.........
	//用Socket API建立简易TCP服务器
	//1.建立一个Socket
    SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//AF_INET表示IPV4类型，SOCK_STREAM表示基于数据流，IPPROTO_TCP表示基于TCP
	//2.bind 绑定用于接受客户端连接的网络端口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;  //指明创建的是IPV4类型
	_sin.sin_port = htons(4567);//htons>>host to net unsigned short  //创建套节字地址，端口号
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//inet_addr("127.0.0.1") //绑定IP地址
	if(SOCKET_ERROR ==  bind(_sock,(sockaddr*)&_sin, sizeof(sockaddr_in))) //三个参数分别是第一步创建的socket，socket的网络地址，数据长度；
	{
		cout << "绑定用于接受客户端连接的网络端口失败\n";
	}
	else
	{
		cout << "绑定用于接受客户端连接的网络端口成功\n";
	}
	//3.listen 监听网络端口
	if (SOCKET_ERROR == listen(_sock, 5))//第一个参数传入一个socket,第二个参数表示最大需要多少人等待连接
	{
		cout << "监听网络端口失败\n";
	}
	else
		cout << "监听网络端口成功\n";
	//4.accept 等待接受客户端连接
	sockaddr_in clientAddr = {};
	int ALength = sizeof(clientAddr);
	SOCKET _cSock = INVALID_SOCKET;
	

	_cSock = accept(_sock, (sockaddr*)&clientAddr, &ALength);//第一个参数仍然是创建的socket,第二个是客户端socket地址;
	if (INVALID_SOCKET == _cSock)
	{
		cout << "接受客户端连接无效\n";
	}
	else
	{
		cout << "接收客户端连接成功\n";
	}
	printf("新客户端加入socket=%d\nIP地址为：%s！\n",(int)_cSock, inet_ntoa(clientAddr.sin_addr));
	char _recvBuf[128] = {};
	while (true)
	{
		DataHeader header = {};
		//5.接收客户端数据
		int nLen = recv(_cSock, (char*)&header, sizeof(DataHeader), 0);
		if (nLen <= 0)
		{
			cout << "客户端已退出，任务结束\n" << endl;
			break;
		}
		switch (header.cmd)
		{
		case CMD_LOGIN:
		{
			Login login = {};
			recv(_cSock, (char*)&login+sizeof(DataHeader), sizeof(Login)-sizeof(DataHeader), 0);
			printf("收到命令：CMD_LOGIN 数据长度%d， userName=%s, passWord = %s\n",header.dataLength,login.userName, login.passWord);
			//忽略判断用户密码是否正确
			LoginResult ret;
			send(_cSock, (char*)&ret, sizeof(LoginResult), 0);
		}
		break;
		case CMD_LOGOUT:
		{
			Logout logout = {};
			recv(_cSock, (char*)&logout+sizeof(DataHeader), sizeof(Logout)-sizeof(DataHeader), 0);
			printf("收到命令：CMD_LOGIN 数据长度%d， userName= %s,\n",logout.dataLength, logout.userName);
			//忽略判断用户密码是否正确
			LogoutResult ret;
			send(_cSock, (char*)&ret, sizeof(ret), 0);
		}
		break;
		default:
			header.cmd = CMD_ERROR;
			header.dataLength = 0;
			send(_cSock, (char*)&header, sizeof(header), 0);
			break;
		}
	}
	
	//6.关闭套节字closesocket
	closesocket(_sock);
	//..........
	//清除Windows Socket环境
	WSACleanup();
	cout << "服务器端结束任务，已退出\n";
	system("pause");
	return 0;

}

