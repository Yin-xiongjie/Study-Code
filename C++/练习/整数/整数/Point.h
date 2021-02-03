#pragma once
#include<iostream>
using namespace std;
class Point
{
private:
	int x1, x2;
	double y1, y2;
public:
	Point(int, int);
	Point(double, double);
	int Get_1();  //+
	int Get_2();  //-
	int Get_3();  //*
	int Get_4();  ///
	double Get_5();  //+
	double Get_6();  //-
	double Get_7();  //*
	double Get_8();  ///

	~Point();
};

