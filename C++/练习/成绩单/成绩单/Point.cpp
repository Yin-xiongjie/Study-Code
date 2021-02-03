#include "Point.h"



Point::Point()
{
}
void Point::GetInfo(int a1)
{
	for (int i = 0; i < a1; i++)
	{
		cout << "学生姓名：";
		cin >> stu[i].name;
		cout << endl;
		cout << stu[i].name<<"的学号是：";
		cin >> stu[i].IDnumber;
		cout << endl;
		cout << "******录入学科成绩******" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学科" <<":"<<setw(2);
			cin >> stu[i].sub_ID[j];
			cout << setw(2) << "的成绩为：" << setw(2);
			cin >> stu[i].sub_marks[j];
			cout << endl;
			//stu[i].sum[i] += stu[i].sub_marks[j];
		}
		//stu[i].ave[i] = stu[i].sum[i] / 5;
	}
}
void Point::GetTotal(int b1)
{
	for (int i = 0; i < b1; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			sum[i] += stu[i].sub_marks[j];
		}
		if (i == b1 - 1)
			break;
	}
}

void Point::Averate(int c1)
{
	for (int i = 0; i < c1; i++)
	{
		ave[i] = 0;
		ave[i] = sum[i] / 5;
		if (i == c1 - 1)
			break;
	}
}

void Point::ShowScore(int d1)
{
	cout << "********显示学生成绩单********" << endl;
	for (int i = 0; i <d1; i++)
	{
		cout << "学生1：" << stu[i].name << endl << "◆◆◆◆◆成绩如下◆◆◆◆◆" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout<< stu[i].sub_ID[j]<<setw(2)<<"的成绩为："<<setw(2)<< stu[i].sub_marks[j]<<endl;
		}
		cout << "总分：" << setw(2) << sum[i] << endl << "平均分：" << setw(2) << ave[i] << endl << '\n';
	}
}
Point::~Point()
{
}
