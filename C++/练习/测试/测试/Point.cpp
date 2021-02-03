#include "Point.h"



//Point::Point()
//{
//}
void Point::disp()
{
	cout << rel << "+" << "i*" << imag << endl;
}

//�ӵ�ʵ��
Point operator + (const Point &c1, const Point &c2)
{
	return Point(c1.rel + c2.rel, c1.imag + c2.imag);
}

//����ʵ��
Point operator - (const Point &c1, const Point &c2)
{
	return Point(c1.rel + c2.rel,c1. imag - c2.imag);
}

//ȡ����ʵ��
Point operator -(const Point &c1)
{
	return Point(-c1.rel, -c1.imag);
}

//�˵�ʵ��
Point operator * (const Point& c1, const Point& c2)
{
	return Point(c1.rel * c2.rel-c1.imag*c2.imag, c1.rel*c2.imag+c1.imag*c2.rel);
}

//����ʵ��
Point operator / (const Point& c1, const Point& c2)
{
	return Point((c1.rel * c2.rel + c1.imag*c2.imag)/(pow(c2.rel,2)+pow(c2.imag,2)), (c1.imag*c2.rel + c1.rel*c2.imag)/ (pow(c2.rel, 2) + pow(c2.imag, 2)));
}



//ǰ��++
Point& operator ++(Point &c1)
{
	cout << "ǰ��++" << endl;
	c1.rel += 1;
	c1.imag += 1;
	return c1;
}

//����++
Point operator ++(Point &c1, int)
{
	cout << "����++" << endl;
	Point ctemp = c1;
	++c1;
	return ctemp;
}

Point::~Point()
{
}
