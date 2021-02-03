#include<iostream>
#include"A.h"
#include"B.h"
#include"D.h"

using namespace std;

int main()
{
	D exD;
	exD.disp();
	exD.A::print();
	return 0;
}