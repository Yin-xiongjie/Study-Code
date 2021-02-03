#include<iostream>
#include"Point.h"
#include<cmath>

using namespace std;


int main()
{
	Point cx1(1.0, 2.0), cx2(3.0, 4.0), cxRes;
	cxRes = cx1 + cx2;			//相当于cx1.operator+cx2;
	cxRes.disp();
	cxRes = cx1 - cx2;			//相当于cx1.operator-cx2;
	cxRes.disp();
	cxRes = cx1 * cx2;			//相当于cx1.operator*cx2;
	cxRes.disp();
	cxRes = cx1 / cx2;			//相当于cx1.operator/cx2;
	cxRes.disp();
	cxRes = -cx1;				//相当于cx1.operator-();
	cxRes.disp();
	Point cx3(1.0, 1.0), cx4(5.0, 5.0);
	cxRes = ++cx3;				//相当于cx3.operator++()
	cxRes.disp();
	cx3.disp();
	cxRes = cx4++;				//相当于cx4.operator++(0)不理解
	cxRes.disp();
	cx4.disp();
	return 0;
}