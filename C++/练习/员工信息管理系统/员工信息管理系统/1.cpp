#include"Employee.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int Employee::count_total = 0;
double Employee::sum = 0;
#define M 100           //员工最大容量
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
				cout << "要添加的员工数量：";
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
	cout << "           *               欢迎使用员工信息管理系统          *             " << endl;
	cout << "           *    1.添加员工信息             2.查询员工信息    *             " << endl;
	cout << "           *    3.修改员工信息             4.删除员工信息    *             " << endl;
	cout << "           *    5.显示所有员工信息         6.计算平均工资    *             " << endl;
	cout << "           *    0.退出系统                                   *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                    输入操作选项                 *             " << endl;
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
		cout << "输入要删除的位置：";
		cin >> i;
		cout << "*********删除操作选项*********" << endl;
		cout << "输入操作选项：";
		cout << "是否确认删除，请输入Y/y" << endl << "输入选择：";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			e[i].total_sub();
			for (j = i + 1; j < count; j++)
			{
				e[j - 1] = e[j];
				count--;
				cout << "删除成功！" << endl;
			}
		}
	}
		
}
//void Employee::total_add()  //添加
//{
//	count_total++;
//	sum += wage;
//}
//
//void Employee::total_sub()   //删除
//{
//	count_total--;
//	sum -= wage;
//}
//
//double Employee::average()    //计算平均工资
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