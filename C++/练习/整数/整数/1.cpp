#include<iostream>
#include"Point.h"
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	int a1, a2;
	double b1, b2;
	string choose1;
	cout << "给两整数赋值：";
	cin >> a1 >> a2;
	cout << endl;
	cout << "给两实数赋值：";
	cin >> b1 >> b2;
	cout << endl;
	Point ptr_1(a1, a2);
	Point ptr_2(b1, b2);
	cout << setw(8) << "菜单" << setw(8) << endl;
	cout << setw(7) << "1.整数加法" << setw(7) << endl;
	cout << setw(7) << "2.整数减法" << setw(7) << endl;
	cout << setw(7) << "3.整数乘法" << setw(7) << endl;
	cout << setw(7) << "4.整数除法" << setw(7) << endl;
	cout << setw(7) << "5.实数加法" << setw(7) << endl;
	cout << setw(7) << "6.实数减法" << setw(7) << endl;
	cout << setw(7) << "7.实数乘法" << setw(7) << endl;
	cout << setw(7) << "8.实数除法" << setw(7) << endl;
	int choose;
	while (1) {
		cout << "用户输入选择：";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "计算结果为："<<ptr_1.Get_1()<<'\n'<<endl;		
			break;
		case 2:	cout << "计算结果为："<<ptr_1.Get_2() << '\n' << endl;
			
			break;
		case 3:	cout << "计算结果为："<< ptr_1.Get_3() << '\n' << endl;
			break;
		case 4:	cout << "计算结果为：" << ptr_1.Get_4() << '\n' << endl;
			break;
		case 5:
			cout << "计算结果为："<< ptr_2.Get_5() << '\n' << endl;
			break;
		case 6:	cout << "计算结果为："<< ptr_2.Get_6() << '\n' << endl;
			break;
		case 7:	cout << "计算结果为："<< ptr_2.Get_7() << '\n' << endl;
			break;
		case 8:	cout << "计算结果为："<< ptr_2.Get_8() << '\n' << endl;
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

}