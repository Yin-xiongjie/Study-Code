#pragma once
#include<iostream>
#include<string>

using namespace std;
class Point
{
private:
	char *brand;
	float price;

public:
	Point(const char* sz, float p)
	{
		brand = new char[strlen(sz) + 1];
		strcpy(brand, sz);
		price = p;
	}
	Point()
	{
		brand = NULL;
		price = 0;
		cout << "无参构造函数被调用" << endl;
	}

	Point(const Point &cp)
	{
		brand = new char[strlen(cp.brand) + 1];
		strcpy(brand, cp.brand);
		price = cp.price;
		cout << "复制构造函数被调用" << endl;
	}
	void print()
	{
		cout << "品牌：" << brand << endl;
		cout << "价格：" << price << endl;
	}
	Point();
	~Point();
};

