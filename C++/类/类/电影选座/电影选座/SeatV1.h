#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class SeatV1
{
public:
	SeatV1();
	~SeatV1();
	vector<string>a1[10];
	string name;		//观影人姓名
	string choice;		//用户选择
	long IDnumber;	//观影人身份证号码
	int age;			//观影人年龄
	char sex[5];		//观影人性别
	
	void Seat();	//初始化座位表
	int  Judge(string); //判断顾客是否购票
	void Customer(string, char, long, int);
	void Showseats();		//打印座位表
	void Traver();			//传递观影人信息
};

