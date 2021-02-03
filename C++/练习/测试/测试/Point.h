#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
	double rel, imag;
public:
	//Point(double, double); 
	friend Point operator + (const Point &, const Point &);			//成员函数形式重载+
	friend Point operator - (const Point &, const Point &);			//成员函数形式重载+
	friend Point operator -(const Point &);							//成员函数形式重载一元（取反）
	friend Point operator * (const Point&, const Point&);		//成员函数形式重载*
	friend Point operator / (const Point&, const Point&);			//成员函数形式重载/
	friend Point& operator ++(Point &);						//成员函数形式重载前置++
	friend Point operator ++(Point &, int);						//成员函数形式重载后置++
	void disp();								//成员函数，输出复数
	Point(double r = 0.0, double i = 0.0)
	{
		rel = r;
		imag = i;
	}
	~Point();
};

