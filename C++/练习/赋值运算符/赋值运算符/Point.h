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
		cout << "�޲ι��캯��������" << endl;
	}

	Point(const Point &cp)
	{
		brand = new char[strlen(cp.brand) + 1];
		strcpy(brand, cp.brand);
		price = cp.price;
		cout << "���ƹ��캯��������" << endl;
	}
	void print()
	{
		cout << "Ʒ�ƣ�" << brand << endl;
		cout << "�۸�" << price << endl;
	}
	Point();
	~Point();
};

