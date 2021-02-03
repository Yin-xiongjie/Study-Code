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
	cout << "输入要存储的信息的新生人数：";
	cin >> num;
	student A[num + 1];
	for (i = 1; i <= num; i++)
	{
		cout << "输入" << i << "号新生信息：" << endl;
		cout << '\t' << '\t' << "姓名：";
		cin >> A[i].name;
		cout << setw(4);
		cout << '\t' << '\t' << "学号：";
		cin >> A[i].num_1;
		cout << '\t' << '\t' << "年龄：";
		cin >> A[i].age;
		cout << setw(4);
		cout << '\t' << '\t' << "性别：";
		cin >> A[i].male;
		cout << setw(4);
		cout << '\t' << '\t' << "联系电话：";
		cin >> A[i].phone;
	}
	while (1)
	{
		cout << setfill('*');
		cout << "*" << setw(37) << "*" << endl;
		cout << "*" << setw(20) << "用户操作菜单" << setw(17) << "*" << endl;
		cout << "*" << setw(19) << "查询学生按1" << setw(18) << "*" << endl;
		cout << "*" << setw(21) << "按学号排序按2" << setw(16) << "*" << endl;
		cout << "*" << setw(37) << "*" << endl;
		cout << "请输入您的选择：";
		cin >> a;
		switch (a)
		{
		case 1: cout << "输入您要查询的学生姓名：";
			char name[15];
			cin >> name;
			cout << endl;
			for (i = 1; i <= num; i++)
			{
				if (strcmp(name, A[i].name) == 0)
				{
					cout << "找到该学生信息为：" << "姓名:" << A[i].name << setw(6) << "学号:"<A[i].num_1 << setw(6) << "年龄:" << A[i].age << setw(6) << "性别:" << A[i].male << setw(6) << "电话:" << A[i].phone << endl;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "该学生不存在。" << endl;
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
			cout << "排序好的学生信息为：" << endl;
			for (i = 1; i <= num; i++)
			{
				cout << "姓名:" << A[i].name << setw(6) << "学号:"<A[i].num_1 << setw(6) << "年龄:" << A[i].age << setw(6) << "性别:" << A[i].male << setw(6) << "电话:" << A[i].phone << endl;
			}
			break;

		}
	}

	/*cout<<"请输入您的选择：";
	cin>>a;
	if(a == 1)
	{
	for(i = 1; i<= num; i++)
	{
	cout<<'\t'<<'\t'<<"姓名："<<A[i].name<<'\t'<<"年龄："<<A[i].age<<'\t'<<"性别："<<A[i].male<<'\t'<<"联系电话："<<A[i].phone<<endl;
	if(i == num)
	{
	cout<<"学生信息打印完毕！！"<<endl;
	}
	}
	}*/
	return 0;
}


