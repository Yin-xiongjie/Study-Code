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
	float* scores;		//学生的分数数组

	

public:
	LandOwnerV1();
	~LandOwnerV1();
	void Showscores();
	int scorecount;				//学生成绩个数
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
	void  Initscores();			//初始化学生成绩数组，默认分配1个元素空间
	void Addscores(float);		//添加成绩
	//书写函数，返回学霸对象
	LandOwnerV1& Getsuperscholar(LandOwnerV1&);
	float Gettotal();
};

