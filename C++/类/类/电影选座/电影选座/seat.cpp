#include<iostream>
#include"SeatV1.h"
#include<iomanip>
#include<string>
using namespace std;
struct CUS					//�洢��Ӱ����Ϣ�Ľṹ������
{
	string _name;
	string _sex;
	long _IDnumber;
	int _age;
}CusInfo[100];

int main()
{

	string choice1;
	string choice2; 			
	string choice3;						
	string choice4;								//choice1����Ʊѡ�choice2�Ĳ鿴��Ϣѡ��,choice3�����ж��Ƿ��ٴι�Ʊ��choice4����ִ�й���ԱȨ��
	long Snumber;
	int temp1, row, line, row1, line1;			//temp�����û�ѡ��ķ���ֵ, rowΪ�У�lineΪ��,	row1,line1Ϊȷ�ϵ�����
	long password;				//����Ա����
	SeatV1 seat1;	
	cout << "���Ƿ�ѡ��Ʊ��" << endl;
	cout << "��" << setw(8) <<"or"<<setw(8)<< "��" << endl;
	cout << "�����룺";
	cin >> choice1;
	temp1 = seat1.Judge(choice1);	//�Ƿ���1���񷵻�0
	if (temp1 == 0)
	{
		exit(0);
	}
	seat1.Showseats();

	//ѡ��λ��
	while (1)
	{
		cout << "��������ѡ���λ��(��[1��3��]���룺1 3)��";
		cin >> row >> line;
		if (row < 1 || row > 10 || line > 10 || line < 1||seat1.a1[row-1][line-1] == "��")
		{
			cout << "��ѡ�����λ�����ڻ��Ѿ�����Ʊ��������ѡ��"<<endl;
			continue;
		}
		cout << endl;
		seat1.a1[row - 1][line - 1] = "��";

		//�洢��Ӱ����Ϣ
		cout << "�������Ӱ����Ϣ" << endl;
		cout << "������";
		cin >> seat1.name;
		CusInfo[(line - 1) * 10 + row - 1]._name = seat1.name;
		cout << endl;
		cout << "�Ա�";
		cin >> seat1.sex;
		CusInfo[(line - 1) * 10 + row - 1]._sex = seat1.sex;
		cout << endl;
		cout << "�������֤���룺";
		cin >> seat1.IDnumber;
		CusInfo[(line - 1) * 10 + row - 1]._IDnumber = seat1.IDnumber;
		cout << endl;
		cout << "���䣺";
		cin >> seat1.age;
		CusInfo[(line - 1) * 10 + row - 1]._age = seat1.age;
		cout << endl;
		seat1.Showseats();  //��ӡѡƱ��λ��

		line1 = 0, row1 = 0;
		cout << "�Ƿ�鿴�Լ���Ϣ��" << endl;							//�û��鿴�Լ���Ϣ
		cout << "��" << setw(8) << "or" << setw(8) << "��" << endl << "����ѡ��";
		cin >> choice2;
		if (choice2 == "��")
		{
			cout <<endl<< "Ϊȷ���Ƿ��Ǳ��˲��������������֤���룡"<<endl;
			cout << endl;
			cout << "���������֤���룺";
			cin >> Snumber;
			cout << endl;
			if(Snumber == seat1.IDnumber)
			cout << "������" << CusInfo[(line - 1) * 10 + row - 1]._name << endl << "�Ա�" << CusInfo[(line - 1) * 10 + row - 1]._sex << endl << "���֤�ţ�"
				<< CusInfo[(line - 1) * 10 + row - 1]._IDnumber << endl << "���䣺" << CusInfo[(line - 1) * 10 + row - 1]._age << endl;
		}
		cout << endl;
		cout << "�Ƿ��������ѡƱ��" << endl;				//�ظ���Ʊѡ��
		cout << "��" << setw(8) << "or" << setw(8) << "��" << endl<<"������ѡ��";
		cin >> choice3;
		cout << endl;
		if (choice3 == "��")
		{
			continue;
		}
		else
		{
			string DD = "��ӭ�ٴι�Ʊ��ף����Ӱ��죡";
			cout << DD<<endl<<'\n';
		}
		break;
	}

	cout << "����Ա�Ƿ�鿴���й�Ӱ����Ϣ��" << endl;				//����ԱȨ�ޣ��鿴�����û���Ϣ
	cout << "��" << setw(8) << "or" << setw(8) << "��" << endl << "������ѡ��";
	cin >> choice4;
	if (choice4 == "��")
	{
		cout << "���������Ա���룡" << endl << "���룺";
		cin >> password;
		if (password == 88088208)
		{
			string name1;
			string choice5;
			while (1) {
				cout << "Ҫ��ѯ�Ĺ�Ӱ��������";
				cin >> name1;
				for (int i = 0; i < 100; i++)
				{
					if (name1 == CusInfo[i]._name)
					{
						cout << "*********��Ӱ�˵���Ϣ����**********" << endl;
						cout << "������" << CusInfo[i]._name << endl << "�Ա�" << CusInfo[i]._sex << endl << "���֤���룺" << CusInfo[i]._IDnumber << endl << "���䣺" << CusInfo[i]._age << '\n' << endl;
					}
				}
				cout << "�Ƿ�����鿴��" << endl << "��" << setw(8) << "or" << setw(8) << "��" << endl << "������ѡ��";
				cin >> choice5;
				if (choice5 == "��")
					break;
			}
			cout << endl;
			cout << "*********���й�Ӱ�˵���Ϣ����**********" << endl;
			
			for (int i = 0; i < 100; i++)
			{
				if (!CusInfo[i]._name.empty())
				{
					cout << "������" << CusInfo[i]._name << endl << "�Ա�" << CusInfo[i]._sex << endl << "���֤���룺" << CusInfo[i]._IDnumber << endl << "���䣺" << CusInfo[i]._age <<'\n'<< endl;
				}
			}
			seat1.Showseats();
		}

	}
	//delete CusInfo;
	return 0;
}
