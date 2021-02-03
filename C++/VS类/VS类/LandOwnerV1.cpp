#include "LandOwnerV1.h"

using namespace std;

LandOwnerV1::LandOwnerV1()
{
	cout << "斗地主打土豪" << endl;
	Initscores();
}													
LandOwnerV1::LandOwnerV1( int age)
{
	Setage(age);
}
LandOwnerV1::LandOwnerV1(string name, string desc) :m_name(name), m_desc(desc) {
	ShowInfo();
	Initscores();
}

void LandOwnerV1::Initscores()
{
	this->scores = new float[1];
	this->scorecount = 1;
}

void LandOwnerV1::ShowInfo()
{
	cout << m_desc << m_name << endl;
	for (int i = 0; i < scorecount; i++)
	{
		cout << this->scores[i] << "\t";
	}
	cout << endl;
}
void LandOwnerV1::Addscores(float score)
{
	this->scores[this->scorecount - 1] = score;
	//1.创建一个新数组，分配SCORECOUNT+1个空间
	//2.复制原数组的数据到新数组
	//3.scorecount++
	//4.scores指向新数组
	float*  newscores = new float[scorecount + 1];
	float*  oldscores = scores;
	memcpy(newscores, scores, sizeof(float)*scorecount);
	scorecount++;
	scores = newscores;
	delete oldscores;
}
void LandOwnerV1::Showscores()
{
	for (int i = 0; i < scorecount - 1; i++)
	{
		cout << this->scores[i] << '\t' ;
	}
	cout << endl;
}
/**
*返回学霸对象
* otherstu 要对比的另外一个学生对象
* return 返回总分比较大的那个学生对象
*/
LandOwnerV1& LandOwnerV1::Getsuperscholar(LandOwnerV1& otherstu)
{
	//分别计算两个学生总分
	if (this->Gettotal > otherstu.Gettotal)
	{
		return *this;
	}
	else
		return otherstu;
}

float LandOwnerV1::Gettotal()
{
	float sum = 0;
	for (int i = 0; i < scorecount - 1; i++) {
		sum += scores[i];
	}
	return sum;
}
LandOwnerV1::~LandOwnerV1()
{
	delete this->scores;
}
