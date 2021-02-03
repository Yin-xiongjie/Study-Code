#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
	double real, imag;
public:
	//int sum;
	Point(double, double);

	Point operator + (const Point&);   //成员函数形式重载+
	Point operator - (const Point&);   //成员函数形式重载-
	Point operator * (const Point&);   //成员函数形式重载*
	Point operator / (const Point&);   //成员函数形式重载/
	void disp()
	{
		cout << real << "+" << "i*" << imag << endl;
	}
	Point();
	~Point();
};
