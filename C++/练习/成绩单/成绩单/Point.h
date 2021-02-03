#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Student
{
	string name;
	long IDnumber;
	int sub_ID[5];
	double sub_marks[5];
	/*double sum[40];
	double ave[40];*/
};
class Point
{
private:
	/*string name;
	int IDnumber;
	int sub_ID[5];
	 sub_marks[5];*/
public:
	Student *stu = new Student[40];
	void GetInfo(int);
	void GetTotal(int);
	void Averate(int);
	void ShowScore(int);
	int num;
	double sum[40];
	double ave[40];
	/*int setnum()
	{
		cin >> num;
		cout << endl;
		return num;
	}*/

	Point();
	~Point();
};

