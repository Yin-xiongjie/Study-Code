#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>

using namespace std;
struct student
{
	char name[20];
	int num_1;
	int age;
	char male[5];
	long phone;
};
struct student1
{
	char name[20];
	int num_1;
	int age;
	char male[5];
	long phone;
};


int main()
{
	int i, num = 5, a, flag = 0, j;
	cout << "����Ҫ�洢����Ϣ������������";
	cin >> num;
	student A[num + 1];
	for (i = 1; i <= num; i++)
	{
		cout << "����" << i << "��������Ϣ��" << endl;
		cout << '\t' << '\t' << "������";
		cin >> A[i].name;
		cout << setw(4);
		cout << '\t' << '\t' << "ѧ�ţ�";
		cin >> A[i].num_1;
		cout << '\t' << '\t' << "���䣺";
		cin >> A[i].age;
		cout << setw(4);
		cout << '\t' << '\t' << "�Ա�";
		cin >> A[i].male;
		cout << setw(4);
		cout << '\t' << '\t' << "��ϵ�绰��";
		cin >> A[i].phone;
	}
	while (1)
	{
		cout << setfill('*');
		cout << "*" << setw(37) << "*" << endl;
		cout << "*" << setw(20) << "�û������˵�" << setw(17) << "*" << endl;
		cout << "*" << setw(19) << "��ѯѧ����1" << setw(18) << "*" << endl;
		cout << "*" << setw(21) << "��ѧ������2" << setw(16) << "*" << endl;
		cout << "*" << setw(37) << "*" << endl;
		cout << "����������ѡ��";
		cin >> a;
		switch (a)
		{
		case 1: cout << "������Ҫ��ѯ��ѧ��������";
			char name[15];
			cin >> name;
			cout << endl;
			for (i = 1; i <= num; i++)
			{
				if (strcmp(name, A[i].name) == 0)
				{
					cout << "�ҵ���ѧ����ϢΪ��" << "����:" << A[i].name << setw(6) << "ѧ��:"<A[i].num_1 << setw(6) << "����:" << A[i].age << setw(6) << "�Ա�:" << A[i].male << setw(6) << "�绰:" << A[i].phone << endl;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "��ѧ�������ڡ�" << endl;
			}
			break;
		case 2:
			int num_2;
			for (i = 1; i < num; i++)
			{
				for (j = 1; j <= num - i; j++)
				{
					if (A[i].num_1>A[i + 1].num_1)
					{
						num_2 = A[i].num_1;
						A[i].num_1 = A[i].num[i + 1];
						A[i].num[i + 1] = num_2;
					}
				}
			}
			cout << "����õ�ѧ����ϢΪ��" << endl;
			for (i = 1; i <= num; i++)
			{
				cout << "����:" << A[i].name << setw(6) << "ѧ��:"<A[i].num_1 << setw(6) << "����:" << A[i].age << setw(6) << "�Ա�:" << A[i].male << setw(6) << "�绰:" << A[i].phone << endl;
			}
			break;

		}
	}

	/*cout<<"����������ѡ��";
	cin>>a;
	if(a == 1)
	{
	for(i = 1; i<= num; i++)
	{
	cout<<'\t'<<'\t'<<"������"<<A[i].name<<'\t'<<"���䣺"<<A[i].age<<'\t'<<"�Ա�"<<A[i].male<<'\t'<<"��ϵ�绰��"<<A[i].phone<<endl;
	if(i == num)
	{
	cout<<"ѧ����Ϣ��ӡ��ϣ���"<<endl;
	}
	}
	}*/
	return 0;
}


