#include"Employee.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int Employee::count_total = 0;
double Employee::sum = 0;
#define M 100           //Ա���������
#define N 9

int menu();
void AddEmployee(Employee *e, int& count);
int main()
{
	Employee *e[M];
	int count = 0;
	while (1)
	{
		switch (menu())
		{
			case 1:
				int sum_1;
				cout << "Ҫ��ӵ�Ա��������";
				cin >> sum_1;
				AddEmployee(*e, sum_1);
		default:
			break;
		}
	}
}


int menu()
{
	cout << "           ***************************************************				" << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *               ��ӭʹ��Ա����Ϣ����ϵͳ          *             " << endl;
	cout << "           *    1.���Ա����Ϣ             2.��ѯԱ����Ϣ    *             " << endl;
	cout << "           *    3.�޸�Ա����Ϣ             4.ɾ��Ա����Ϣ    *             " << endl;
	cout << "           *    5.��ʾ����Ա����Ϣ         6.����ƽ������    *             " << endl;
	cout << "           *    0.�˳�ϵͳ                                   *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                    �������ѡ��                 *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           ***************************************************             " << endl;
	int n;
	cin >> n;
	return n;
}

void AddEmployee(Employee *e, int& count)
{
	string m_name;
	int age;
	long num;
	char *sex;
	double salary;
	e[count] = Employee(m_name, age, num, sex, salary);
	e[count].total_add();
	count++;

}

void DeleteEmployee(Employee *e, int& count)
{
	int i, j, flag, type;
	char ch;
	while (1)
	{
		int i;
		cout << "����Ҫɾ����λ�ã�";
		cin >> i;
		cout << "*********ɾ������ѡ��*********" << endl;
		cout << "�������ѡ�";
		cout << "�Ƿ�ȷ��ɾ����������Y/y" << endl << "����ѡ��";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			e[i].total_sub();
			for (j = i + 1; j < count; j++)
			{
				e[j - 1] = e[j];
				count--;
				cout << "ɾ���ɹ���" << endl;
			}
		}
	}
		
}
//void Employee::total_add()  //���
//{
//	count_total++;
//	sum += wage;
//}
//
//void Employee::total_sub()   //ɾ��
//{
//	count_total--;
//	sum -= wage;
//}
//
//double Employee::average()    //����ƽ������
//{
//	if (count_total == 0)
//		return 0;
//	else
//		return sum / count_total;
//}
//void addemployee(Employee *e, int &count)
//{
//	
//}