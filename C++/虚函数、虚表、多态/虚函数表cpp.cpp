#include<iostream>
#include<string>
using namespace std;

class Wood {
protected:
	//����
	string name;
	int weight;
public:
	Wood(string n, int w) {
		name = n;
		weight = w;
	}
	//����
	virtual void show() {  //����Ϊ�麯��  �������п�����д����
		cout << "����һ��" << weight << "KG��" << name <<endl;
	}
};
//�̳�
class Desk:public Wood{
public:
	Desk(string n, int w) :Wood(n, w) {}
	void show(){
		//cout << "����һ��" << weight << "KG��" << name << "���ɵ�����"<<endl;
		cout << "Desk��show()����" << endl;
	} //

};
class Stool :public Wood {
public:
	Stool(string n, int w) :Wood(n, w) {} //
	void show() {
		cout << "����һ��" << weight << "KG��" << name << "���ɵİ��" << endl;
	} //
};
#if 0
void test(Wood* p);

int main() {
	Wood w1("�ƻ���", 10), w2("��˿�",20), w3("����",8);
	Desk d1("����", 12);
	Stool s1("����", 30);
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
	Wood w1("�ƻ���", 10);
	Desk d1("����", 20);

	int* p = (int*)&d1;

	printf("%p\n", *p);

	printf("%p\n", *((int*)*p)); 
	FUNC pFunc = (FUNC)*((int*)*p);
	pFunc();
	system("pause");
	return 0;
}