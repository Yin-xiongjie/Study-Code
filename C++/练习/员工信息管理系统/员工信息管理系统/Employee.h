#pragma once
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//int Employee::count_total = 0;
//double Employee::sum = 0;

//**************����Ա����****************
class Employee
{
private:
	string name;
	int age;
	long num;
	char *sex;
	double salary;

	static int count_total;      //Ա������
	static double sum;           //Ա�������ܺ�
public:
	int count = 0;
	double wage;
	static double average();	 //����ƽ������
	void total_add();            //���ʱԱ��������һ�������ۼ�
	void total_sub();            //���ʱԱ��������һ�����ʿ۳�
	void Find_Info();            //��ѯԱ����Ϣ
	void Delete_Info();			 //ɾ��Ա����Ϣ
	int menu();					 //�û����溯��
	Employee(string, int, long, char*,double);
	~Employee();
};

