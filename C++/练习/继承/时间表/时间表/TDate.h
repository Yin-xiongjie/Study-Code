#pragma once
#include<iostream>
#include<string>
using namespace std;
class TDate
{
private:
	int day;
	int month;
	int year;
public:
	TDate(int,int,int);
	~TDate();
	/*int Getyear(int);
	int Getmonth(int);
	int Getday(int);*/
friend void print(TDate &);
};

