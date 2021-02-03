#include<iostream>
#include<string>
using namespace std;

class Wood {
protected:
	//属性
	string name;
	int weight;
public:
	Wood(string n, int w) {
		name = n;
		weight = w;
	}
	//功能
	virtual void show() {  //声明为虚函数  派生类中可以重写函数
		cout << "这是一块" << weight << "KG的" << name <<endl;
	}
};
//继承
class Desk:public Wood{
public:
	Desk(string n, int w) :Wood(n, w) {}
	void show(){
		//cout << "这是一块" << weight << "KG的" << name << "做成的桌子"<<endl;
		cout << "Desk的show()函数" << endl;
	} //

};
class Stool :public Wood {
public:
	Stool(string n, int w) :Wood(n, w) {} //
	void show() {
		cout << "这是一块" << weight << "KG的" << name << "做成的板凳" << endl;
	} //
};
#if 0
void test(Wood* p);

int main() {
	Wood w1("黄花梨", 10), w2("金丝楠",20), w3("沉香",8);
	Desk d1("白杨", 12);
	Stool s1("柏树", 30);
	Wood* p;
	p = &w1;
	test(p);

	p = &d1;
	test(p);

	p = &s1;
	test(p);

	d1.show();
	s1.show();
	w1.show();
	w2.show();
	w3.show();
};

void test(Wood* p)
{
	p->show();
}
#endif
//int n				 ------>  int
//void show()		 ------> void ()()   --->  void(*)()
typedef void(*FUNC)();
int main()
{
	Wood w1("黄花梨", 10);
	Desk d1("柏树", 20);

	int* p = (int*)&d1;

	printf("%p\n", *p);

	printf("%p\n", *((int*)*p)); 
	FUNC pFunc = (FUNC)*((int*)*p);
	pFunc();
	system("pause");
	return 0;
}