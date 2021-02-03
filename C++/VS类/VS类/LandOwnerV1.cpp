#include "LandOwnerV1.h"

using namespace std;

LandOwnerV1::LandOwnerV1()
{
	cout << "������������" << endl;
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
	//1.����һ�������飬����SCORECOUNT+1���ռ�
	//2.����ԭ��������ݵ�������
	//3.scorecount++
	//4.scoresָ��������
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
*����ѧ�Զ���
* otherstu Ҫ�Աȵ�����һ��ѧ������
* return �����ֱܷȽϴ���Ǹ�ѧ������
*/
LandOwnerV1& LandOwnerV1::Getsuperscholar(LandOwnerV1& otherstu)
{
	//�ֱ��������ѧ���ܷ�
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
