#include "Point.h"



Point::Point(int i, int j)
{
	x1 = i;
	x2 = j;
}
Point::Point(double i, double j)
{
	y1 = i;
	y2 = j;
}
//������
int Point::Get_1()
{
	return (x1 + x2);
}
//������
int Point::Get_2()
{
	return (x1 - x2);
}
//������
int Point::Get_3()
{
	return (x1 * x2);
}
//������
int Point::Get_4()
{
	return (x1 / x2);
}
//ʵ����
double Point::Get_5()
{
	return (y1 + y2);
}
//ʵ����
double Point::Get_6()
{
	return (y1 - y2);
}
//ʵ����
double Point::Get_7()
{
	return (y1 * y2);
}
//ʵ����
double Point::Get_8()
{
	return (y1 / y2);
}

Point::~Point()
{
}
