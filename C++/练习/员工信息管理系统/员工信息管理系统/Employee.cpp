#include "Employee.h"



Employee::Employee(string name1, int age1, long num1, char *sex1, double salary1)
{
	name = name1;
	age = age1;
	num = num1;
	sex = sex1;
	salary = salary1;
}

void Employee::total_add()  //添加
{
	count_total++;
	sum += wage;
}

void Employee::total_sub()   //删除
{
	count_total--;
	sum -= wage;
}

double Employee::average()    //计算平均工资
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
