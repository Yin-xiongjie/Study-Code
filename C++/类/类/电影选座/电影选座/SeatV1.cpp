#include "SeatV1.h"


SeatV1::SeatV1()
{
	for (int i = 0; i < 10; i++)		//初始化座位表，全部置0
	{
		for (int j = 0; j < 10; j++)
		{
			a1[i].push_back("□");
		}
	}

	cout << setw(4);
	for (int i = 0; i < 10; i++)		//打印座位表
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a1[i][j]<<setw(4);
		}
		cout << endl;
	}
}		//模拟座位表，□为空座，■为已选座位

int SeatV1::Judge(string choice)	//判断顾客是否购票，是返回1，否返回0
{
	if (choice == "是")
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
	cout << "清理空间" << endl;
}
