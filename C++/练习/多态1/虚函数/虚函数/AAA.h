#pragma once
#include<iostream>

using namespace std;

class Fish :
{
public:
	Fish()
	{
		cout << "Constructed Fish" << endl;
	}
	 void printf()
	{
		cout << "打印成功！" << endl;
	}
	virtual ~Fish()
	{
		cout << "Destory Fish" << endl;
	}
};

class Tuna final :  public Fish
{
public:
	Tuna()
	{
		cout << "Constructed Tuna" << endl;
	}
	void printf()
	{
		cout << "打印失败！" << endl;
	}
	virtual ~Tuna()
	{
		cout << "Destory Tuna" << endl;
	}

};



