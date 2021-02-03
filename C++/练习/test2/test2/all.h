#pragma once
#include<iostream>
using namespace std;
class all
{
	friend void print(all &);
private:
	int x, y;
public:
	all(int, int);
	~all();
};

