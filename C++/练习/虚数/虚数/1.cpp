#include<iostream>
#include"Point.h"
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	double real1, imag1, real2, imag2;
	string choose1;
	cout << "********输入实部和虚部***********" << endl;
	cout << "***********第一个虚数**********" << endl;
	cout << "实部：";
	cin >> real1;
	cout << setw(4) << "虚部：";
	cin >> imag1;
	cout << "***********第二个虚数**********" << endl;
	cout << "实部：";
	cin >> real2;
	cout << setw(4) << "虚部：";
	cin >> imag2;
	Point cx1(real1, imag1), cx2(real2, imag2), cxRes;
	cout << setw(8) << "菜单" << setw(8) << endl;
	cout << setw(7) << "1.加法" << setw(7) << endl;
	cout << setw(7) << "2.减法" << setw(7) << endl;
	cout << setw(7) << "3.乘法" << setw(7) << endl;
	cout << setw(7) << "4.除法" << setw(7) << endl;
	int choose;
	while(1){
	cout << "用户输入选择：";
	cin >> choose;
	switch (choose)
	{
	case 1:cxRes = cx1 + cx2;			//相当于cx1.operator+cx2;
		cxRes.disp();
		break;
	case 2:	cxRes = cx1 - cx2;			//相当于cx1.operator-cx2;
		cxRes.disp();
		break;
	case 3:	cxRes = cx1 * cx2;			//相当于cx1.operator*cx2;
		cxRes.disp();
		break;
	case 4:	cxRes = cx1 / cx2;			//相当于cx1.operator/cx2;
		cxRes.disp();
		break;
	default:
		break;
	}
	cout << "是否继续计算？" << endl;
	cout << "是     or     否" << endl << "输入选择：";
	cin >> choose1;
	if (choose1 == "是")
		continue;
	else
		break;
	}
	return 0;
}