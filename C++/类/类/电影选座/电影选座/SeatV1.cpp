#include "SeatV1.h"


SeatV1::SeatV1()
{
	for (int i = 0; i < 10; i++)		//��ʼ����λ��ȫ����0
	{
		for (int j = 0; j < 10; j++)
		{
			a1[i].push_back("��");
		}
	}

	cout << setw(4);
	for (int i = 0; i < 10; i++)		//��ӡ��λ��
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a1[i][j]<<setw(4);
		}
		cout << endl;
	}
}		//ģ����λ����Ϊ��������Ϊ��ѡ��λ

int SeatV1::Judge(string choice)	//�жϹ˿��Ƿ�Ʊ���Ƿ���1���񷵻�0
{
	if (choice == "��")
		return 1;
	else
		return 0;
}
void SeatV1::Showseats()
{
	cout << setw(4);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a1[i][j]<<setw(4);
		}
		cout << endl;
	}
}

SeatV1::~SeatV1()
{
	delete[] a1;
	cout << "����ռ�" << endl;
}
