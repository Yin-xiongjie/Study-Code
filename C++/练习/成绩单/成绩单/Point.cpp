#include "Point.h"



Point::Point()
{
}
void Point::GetInfo(int a1)
{
	for (int i = 0; i < a1; i++)
	{
		cout << "ѧ��������";
		cin >> stu[i].name;
		cout << endl;
		cout << stu[i].name<<"��ѧ���ǣ�";
		cin >> stu[i].IDnumber;
		cout << endl;
		cout << "******¼��ѧ�Ƴɼ�******" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "ѧ��" <<":"<<setw(2);
			cin >> stu[i].sub_ID[j];
			cout << setw(2) << "�ĳɼ�Ϊ��" << setw(2);
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
	cout << "********��ʾѧ���ɼ���********" << endl;
	for (int i = 0; i <d1; i++)
	{
		cout << "ѧ��1��" << stu[i].name << endl << "�����������ɼ����¡���������" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout<< stu[i].sub_ID[j]<<setw(2)<<"�ĳɼ�Ϊ��"<<setw(2)<< stu[i].sub_marks[j]<<endl;
		}
		cout << "�ܷ֣�" << setw(2) << sum[i] << endl << "ƽ���֣�" << setw(2) << ave[i] << endl << '\n';
	}
}
Point::~Point()
{
}
