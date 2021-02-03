#include<iostream>
#include"Point.h"
#include<iomanip>
using namespace std;

int setnum()
{
	int num;
	cin >> num;
	cout << endl;
	return num;
}
int main()
{
	Point ptr_1;
	int num1;
	cout << "输入学生个数：";
	num1 = setnum();
	cout << setprecision(2);
	cout << fixed;
	cout << "********录入学生信息********" << endl;
	ptr_1.GetInfo(num1);
	ptr_1.GetTotal(num1);
	ptr_1.Averate(num1);
	ptr_1.ShowScore(num1);
	return 0;
}