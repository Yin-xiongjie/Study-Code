#include "Point.h"



//Point::Point()
//{
//}
void Point::disp()
{
	cout << rel << "+" << "i*" << imag << endl;
}

//加的实现
Point operator + (const Point &c1, const Point &c2)
{
	return Point(c1.rel + c2.rel, c1.imag + c2.imag);
}

//减的实现
Point operator - (const Point &c1, const Point &c2)
{
	return Point(c1.rel + c2.rel,c1. imag - c2.imag);
}

//取反的实现
Point operator -(const Point &c1)
{
	return Point(-c1.rel, -c1.imag);
}

//乘的实现
Point operator * (const Point& c1, const Point& c2)
{
	return Point(c1.rel * c2.rel-c1.imag*c2.imag, c1.rel*c2.imag+c1.imag*c2.rel);
}

//除的实现
Point operator / (const Point& c1, const Point& c2)
{
	return Point((c1.rel * c2.rel + c1.imag*c2.imag)/(pow(c2.rel,2)+pow(c2.imag,2)), (c1.imag*c2.rel + c1.rel*c2.imag)/ (pow(c2.rel, 2) + pow(c2.imag, 2)));
}



//前置++
Point& operator ++(Point &c1)
{
	cout << "前置++" << endl;
	c1.rel += 1;
	c1.imag += 1;
	return c1;
}

//后置++
Point operator ++(Point &c1, int)
{
	cout << "后置++" << endl;
	Point ctemp = c1;
	++c1;
	return ctemp;
}

Point::~Point()
{
}
