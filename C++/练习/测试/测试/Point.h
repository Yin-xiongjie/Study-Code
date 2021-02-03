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
	friend Point operator + (const Point &, const Point &);			//��Ա������ʽ����+
	friend Point operator - (const Point &, const Point &);			//��Ա������ʽ����+
	friend Point operator -(const Point &);							//��Ա������ʽ����һԪ��ȡ����
	friend Point operator * (const Point&, const Point&);		//��Ա������ʽ����*
	friend Point operator / (const Point&, const Point&);			//��Ա������ʽ����/
	friend Point& operator ++(Point &);						//��Ա������ʽ����ǰ��++
	friend Point operator ++(Point &, int);						//��Ա������ʽ���غ���++
	void disp();								//��Ա�������������
	Point(double r = 0.0, double i = 0.0)
	{
		rel = r;
		imag = i;
	}
	~Point();
};

