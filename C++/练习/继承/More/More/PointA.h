#pragma once
#include<iostream>

using namespace std;

class PointA
{
private:
	int x;
public:
	PointA(int xp = 0)
	{
		x = xp;
		cout << "PointA�Ĺ��캯����ִ��" << endl;
	}
};																								
class PointB 
{
public:
	PointB()
	{
		cout << "PointB�Ĺ��캯����ִ��" << endl;
	}
};
class PointC :public PointA
{
private:
	int y;
	PointB b;
public:
	PointC(int xp, int yp) :PointA(xp), b()
	{
		y = yp;
		cout << "PointC�Ĺ��캯����ִ��" << endl;
	}
};
class PointD : public PointB , public PointC
{																	
};