#include<iostream>
#include<string>
using namespace std;
template <typename T>
T add(const T &t1, const T &t2);
//template double add  <double>(const double &t1, const double &t2);
template int add <int>(const int &t1, const int &t2);
template <typename T>
T add(const T &t1, const T &t2)
{
	return t1 + t2;
}

template<typename A>
void Getname(const A &n1, const A &n2)
{
	cout << "A的名字是：" << n1 << endl;
	cout << "B的名字是：" << n2 << endl;
}
int main()
{
	cout << add(1, 9) << endl;
	cout << add(1.0, 2.9) << endl;
	string x("Hello,"), y("world");
	cout << add(x, y) << endl;

	string a1("小明"), a2("小刚");
	Getname(a1, a2);
	return 0;
}
//template <typename T>
//T add(const T &t1, const T &t2)
//{
//	return t1 + t2;
//}
