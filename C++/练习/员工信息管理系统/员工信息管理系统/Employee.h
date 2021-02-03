#pragma once
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//int Employee::count_total = 0;
//double Employee::sum = 0;

//**************定义员工类****************
class Employee
{
private:
	string name;
	int age;
	long num;
	char *sex;
	double salary;

	static int count_total;      //员工计数
	static double sum;           //员工工资总和
public:
	int count = 0;
	double wage;
	static double average();	 //计算平均工资
	void total_add();            //添加时员工人数加一，工资累加
	void total_sub();            //添加时员工人数减一，工资扣除
	void Find_Info();            //查询员工信息
	void Delete_Info();			 //删除员工信息
	int menu();					 //用户界面函数
	Employee(string, int, long, char*,double);
	~Employee();
};

