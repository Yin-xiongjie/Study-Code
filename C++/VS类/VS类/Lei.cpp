#include<iostream>
#include "LandOwnerV1.h"
using  namespace std;
int main()
{

	LandOwnerV1* ptr_student1 = new LandOwnerV1("�ܿ���", "�ڴ�����");
	ptr_student1->Addscores(81.9f);
	ptr_student1->Addscores(81.9f);
	ptr_student1->Addscores(91.9f);
	ptr_student1->Addscores(771.9f);
	ptr_student1->Addscores(101.9f);
	ptr_student1->Addscores(281.9f);
	ptr_student1->Showscores();
	ptr_student1->ShowInfo();

	LandOwnerV1 stu2 = {"��ǿ��","��־С��" };
	stu2.Addscores(85);
	stu2.Addscores(75);
	stu2.Addscores(65);
	stu2.Addscores(45);
	stu2.Addscores(185);
	LandOwnerV1 scholar = stu2.Getsuperscholar(*ptr_student1);
}