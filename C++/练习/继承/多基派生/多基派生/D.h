#pragma once
#include<iostream>
#include"B.h"
#include"A.h"
class D:public A,public B
{
public:
	void disp()
	{
		A::print();
		B::print();
	}
	D();
	~D();
};

