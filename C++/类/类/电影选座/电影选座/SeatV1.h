#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class SeatV1
{
public:
	SeatV1();
	~SeatV1();
	vector<string>a1[10];
	string name;		//��Ӱ������
	string choice;		//�û�ѡ��
	long IDnumber;	//��Ӱ�����֤����
	int age;			//��Ӱ������
	char sex[5];		//��Ӱ���Ա�
	
	void Seat();	//��ʼ����λ��
	int  Judge(string); //�жϹ˿��Ƿ�Ʊ
	void Customer(string, char, long, int);
	void Showseats();		//��ӡ��λ��
	void Traver();			//���ݹ�Ӱ����Ϣ
};

