#pragma once
#include<iostream>
#include<string>
using namespace std;
class Guest
{
private:
	int m_num = 0;
	string m_name;
	long r_number;
	double m_fee;
	static int count;
public:
	double fee_num;
	double feesum();
	//int Get_num(int);
	string Get_name(string);
	long Get_number(long);
	double Get_fee(double);
	Guest();
	~Guest();
};

