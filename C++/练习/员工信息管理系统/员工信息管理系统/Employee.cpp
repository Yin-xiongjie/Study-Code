#include "Employee.h"



Employee::Employee(string name1, int age1, long num1, char *sex1, double salary1)
{
	name = name1;
	age = age1;
	num = num1;
	sex = sex1;
	salary = salary1;
}

void Employee::total_add()  //���
{
	count_total++;
	sum += wage;
}

void Employee::total_sub()   //ɾ��
{
	count_total--;
	sum -= wage;
}

double Employee::average()    //����ƽ������
{
	if (count_total == 0)
		return 0;
	else
		return sum / count_total;
}
void addemployee(Employee *e, int &count)
{

}
Employee::~Employee()
{
}
