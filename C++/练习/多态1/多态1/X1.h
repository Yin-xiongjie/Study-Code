#pragma once
#include<iostream>
using namespace std;
class X1
{
public:
	void f1() { cout<<"X1::f1,"; f2(); }
	virtual void f2() { cout << "X1::f2,"; }
	X1();
	~X1();
};

class X2
{
public:
	void f2() { cout << "X2::f1,"; f3(); }
	virtual void f3() { cout << "X2::f3,"; }

};
class Y2 :public X1, public X2 {
public:
	Y2() {
		cout << "Y2类构造函数开始";
			f1();
		cout << "Y2类构造函数结束" << endl;
	}
	virtual void f2() { cout << "Y2::f2()", f3(); }
	void f5() { cout << "Y2::f5()\n"; }
};

class Y1
{
public:
	void f4() { cout << "Y1::f4,"; f5(); }
	void f5() { cout << "Y1::f5,"; }

private:

};
class Z :public Y1, public Y2
{
public:
	virtual void f3() { cout << "z::f3, "; f4(); }
	void f5() { cout << "z::f5,\n"; }
};
class W :public Z
{
public:
	virtual void f3() { cout << "W::f3, "; f4(); }
	void f1() { cout << "W::f1,\n"; }
};


