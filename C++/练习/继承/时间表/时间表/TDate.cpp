#include "TDate.h"



TDate::TDate(int a1, int a2, int a3)
{
	year = a1;
	month = a2;
	day = a3;
}
void print(TDate &P1)
{
	
	cout << "*******时间如下*******" << endl;
	cout << P1.year << "-" << P1.month << "-" << P1.day<<endl;
}

TDate::~TDate()
{
}
