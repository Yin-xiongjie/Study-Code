#include<iostream>
#include"Point.h"
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	double real1, imag1, real2, imag2;
	string choose1;
	cout << "********����ʵ�����鲿***********" << endl;
	cout << "***********��һ������**********" << endl;
	cout << "ʵ����";
	cin >> real1;
	cout << setw(4) << "�鲿��";
	cin >> imag1;
	cout << "***********�ڶ�������**********" << endl;
	cout << "ʵ����";
	cin >> real2;
	cout << setw(4) << "�鲿��";
	cin >> imag2;
	Point cx1(real1, imag1), cx2(real2, imag2), cxRes;
	cout << setw(8) << "�˵�" << setw(8) << endl;
	cout << setw(7) << "1.�ӷ�" << setw(7) << endl;
	cout << setw(7) << "2.����" << setw(7) << endl;
	cout << setw(7) << "3.�˷�" << setw(7) << endl;
	cout << setw(7) << "4.����" << setw(7) << endl;
	int choose;
	while(1){
	cout << "�û�����ѡ��";
	cin >> choose;
	switch (choose)
	{
	case 1:cxRes = cx1 + cx2;			//�൱��cx1.operator+cx2;
		cxRes.disp();
		break;
	case 2:	cxRes = cx1 - cx2;			//�൱��cx1.operator-cx2;
		cxRes.disp();
		break;
	case 3:	cxRes = cx1 * cx2;			//�൱��cx1.operator*cx2;
		cxRes.disp();
		break;
	case 4:	cxRes = cx1 / cx2;			//�൱��cx1.operator/cx2;
		cxRes.disp();
		break;
	default:
		break;
	}
	cout << "�Ƿ�������㣿" << endl;
	cout << "��     or     ��" << endl << "����ѡ��";
	cin >> choose1;
	if (choose1 == "��")
		continue;
	else
		break;
	}
	return 0;
}