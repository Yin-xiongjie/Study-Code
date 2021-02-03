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
		cout << "PointA的构造函数被执行" << endl;
	}
};																								
class PointB 
{
public:
	PointB()
	{
		cout << "PointB的构造函数被执行" << endl;
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
		cout << "PointC的构造函数被执行" << endl;
	}
};
class PointD : public PointB , public PointC
{																	
};