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

	Point operator + (const Point&);   //��Ա������ʽ����+
	Point operator - (const Point&);   //��Ա������ʽ����-
	Point operator * (const Point&);   //��Ա������ʽ����*
	Point operator / (const Point&);   //��Ա������ʽ����/
	void disp()
	{
		cout << real << "+" << "i*" << imag << endl;
	}
	Point();
	~Point();
};
