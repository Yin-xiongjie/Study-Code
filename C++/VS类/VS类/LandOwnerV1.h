#pragma once
#include<iostream>
#include<string>

using namespace std;
class LandOwnerV1
{
private:
	string m_name;
	string m_desc;
	int m_age;
	long score;
	float* scores;		//ѧ���ķ�������

	

public:
	LandOwnerV1();
	~LandOwnerV1();
	void Showscores();
	int scorecount;				//ѧ���ɼ�����
	void ShowInfo();
	LandOwnerV1(string, string);
	LandOwnerV1(int);
	void Show_student();
	string Getname() { return m_name; }
	void Setname(string val) { m_name = val; }
	string Getdesc() { return m_desc; }
	void Setage(string val) { m_desc = val; }
	int Getage() { return m_age; }
	void Setage(int val)
	{
		if (val < 0)
			m_age = 18;
		else
			m_age = val;
	}
	void  Initscores();			//��ʼ��ѧ���ɼ����飬Ĭ�Ϸ���1��Ԫ�ؿռ�
	void Addscores(float);		//��ӳɼ�
	//��д����������ѧ�Զ���
	LandOwnerV1& Getsuperscholar(LandOwnerV1&);
	float Gettotal();
};

