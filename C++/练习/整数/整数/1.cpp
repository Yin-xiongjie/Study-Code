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
	cout << "����������ֵ��";
	cin >> a1 >> a2;
	cout << endl;
	cout << "����ʵ����ֵ��";
	cin >> b1 >> b2;
	cout << endl;
	Point ptr_1(a1, a2);
	Point ptr_2(b1, b2);
	cout << setw(8) << "�˵�" << setw(8) << endl;
	cout << setw(7) << "1.�����ӷ�" << setw(7) << endl;
	cout << setw(7) << "2.��������" << setw(7) << endl;
	cout << setw(7) << "3.�����˷�" << setw(7) << endl;
	cout << setw(7) << "4.��������" << setw(7) << endl;
	cout << setw(7) << "5.ʵ���ӷ�" << setw(7) << endl;
	cout << setw(7) << "6.ʵ������" << setw(7) << endl;
	cout << setw(7) << "7.ʵ���˷�" << setw(7) << endl;
	cout << setw(7) << "8.ʵ������" << setw(7) << endl;
	int choose;
	while (1) {
		cout << "�û�����ѡ��";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "������Ϊ��"<<ptr_1.Get_1()<<'\n'<<endl;		
			break;
		case 2:	cout << "������Ϊ��"<<ptr_1.Get_2() << '\n' << endl;
			
			break;
		case 3:	cout << "������Ϊ��"<< ptr_1.Get_3() << '\n' << endl;
			break;
		case 4:	cout << "������Ϊ��" << ptr_1.Get_4() << '\n' << endl;
			break;
		case 5:
			cout << "������Ϊ��"<< ptr_2.Get_5() << '\n' << endl;
			break;
		case 6:	cout << "������Ϊ��"<< ptr_2.Get_6() << '\n' << endl;
			break;
		case 7:	cout << "������Ϊ��"<< ptr_2.Get_7() << '\n' << endl;
			break;
		case 8:	cout << "������Ϊ��"<< ptr_2.Get_8() << '\n' << endl;
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

}