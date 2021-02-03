#include "Point.h"



//+��ʵ��
Point::Point()
{
}
Point Point::operator + (const Point&cc)
{
	return Point(real + cc.real, imag + cc.imag);
}

//-��ʵ��
Point Point::operator - (const Point&cc)
{
	return Point(real - cc.real, imag - cc.imag);
}

//*��ʵ��
Point Point::operator * (const Point&cc)
{
	return Point(real * cc.real - imag*cc.imag, real*cc.imag + imag*cc.real);
}

// /��ʵ��
Point Point::operator / (const Point&cc)
{
	return Point((real*cc.real - imag*cc.imag) / (cc.real*cc.real + cc.imag*cc.imag), (imag*cc.real - real*cc.imag) / (cc.real*cc.real + cc.imag*cc.imag));
}
Point::Point(double i, double j)
{
	real = i;
	imag = j;
}


Point::~Point()
{
}
