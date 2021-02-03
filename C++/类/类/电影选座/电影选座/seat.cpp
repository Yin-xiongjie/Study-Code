#include<iostream>
#include"SeatV1.h"
#include<iomanip>
#include<string>
using namespace std;
struct CUS					//存储观影人信息的结构体数组
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
	string choice4;								//choice1是买票选项，choice2的查看信息选项,choice3用来判断是否再次购票，choice4用来执行管理员权限
	long Snumber;
	int temp1, row, line, row1, line1;			//temp接收用户选择的返回值, row为行，line为列,	row1,line1为确认的行列
	long password;				//管理员密码
	SeatV1 seat1;	
	cout << "您是否选择购票？" << endl;
	cout << "是" << setw(8) <<"or"<<setw(8)<< "否" << endl;
	cout << "请输入：";
	cin >> choice1;
	temp1 = seat1.Judge(choice1);	//是返回1，否返回0
	if (temp1 == 0)
	{
		exit(0);
	}
	seat1.Showseats();

	//选择位置
	while (1)
	{
		cout << "请输入您选择的位置(例[1行3列]输入：1 3)：";
		cin >> row >> line;
		if (row < 1 || row > 10 || line > 10 || line < 1||seat1.a1[row-1][line-1] == "■")
		{
			cout << "您选择的座位不存在或已经被购票，请重新选择！"<<endl;
			continue;
		}
		cout << endl;
		seat1.a1[row - 1][line - 1] = "■";

		//存储观影人信息
		cout << "请输入观影人信息" << endl;
		cout << "姓名：";
		cin >> seat1.name;
		CusInfo[(line - 1) * 10 + row - 1]._name = seat1.name;
		cout << endl;
		cout << "性别：";
		cin >> seat1.sex;
		CusInfo[(line - 1) * 10 + row - 1]._sex = seat1.sex;
		cout << endl;
		cout << "居民身份证号码：";
		cin >> seat1.IDnumber;
		CusInfo[(line - 1) * 10 + row - 1]._IDnumber = seat1.IDnumber;
		cout << endl;
		cout << "年龄：";
		cin >> seat1.age;
		CusInfo[(line - 1) * 10 + row - 1]._age = seat1.age;
		cout << endl;
		seat1.Showseats();  //打印选票座位表

		line1 = 0, row1 = 0;
		cout << "是否查看自己信息？" << endl;							//用户查看自己信息
		cout << "是" << setw(8) << "or" << setw(8) << "否" << endl << "输入选择：";
		cin >> choice2;
		if (choice2 == "是")
		{
			cout <<endl<< "为确认是否是本人操作，请输入身份证号码！"<<endl;
			cout << endl;
			cout << "请输入身份证号码：";
			cin >> Snumber;
			cout << endl;
			if(Snumber == seat1.IDnumber)
			cout << "姓名：" << CusInfo[(line - 1) * 10 + row - 1]._name << endl << "性别：" << CusInfo[(line - 1) * 10 + row - 1]._sex << endl << "身份证号："
				<< CusInfo[(line - 1) * 10 + row - 1]._IDnumber << endl << "年龄：" << CusInfo[(line - 1) * 10 + row - 1]._age << endl;
		}
		cout << endl;
		cout << "是否继续进行选票？" << endl;				//重复买票选项
		cout << "是" << setw(8) << "or" << setw(8) << "否" << endl<<"请输入选择：";
		cin >> choice3;
		cout << endl;
		if (choice3 == "是")
		{
			continue;
		}
		else
		{
			string DD = "欢迎再次购票，祝您观影愉快！";
			cout << DD<<endl<<'\n';
		}
		break;
	}

	cout << "管理员是否查看所有观影人信息？" << endl;				//管理员权限，查看所有用户信息
	cout << "是" << setw(8) << "or" << setw(8) << "否" << endl << "请输入选择：";
	cin >> choice4;
	if (choice4 == "是")
	{
		cout << "请输入管理员密码！" << endl << "密码：";
		cin >> password;
		if (password == 88088208)
		{
			string name1;
			string choice5;
			while (1) {
				cout << "要查询的观影人姓名：";
				cin >> name1;
				for (int i = 0; i < 100; i++)
				{
					if (name1 == CusInfo[i]._name)
					{
						cout << "*********观影人的信息如下**********" << endl;
						cout << "姓名：" << CusInfo[i]._name << endl << "性别：" << CusInfo[i]._sex << endl << "身份证号码：" << CusInfo[i]._IDnumber << endl << "年龄：" << CusInfo[i]._age << '\n' << endl;
					}
				}
				cout << "是否继续查看？" << endl << "是" << setw(8) << "or" << setw(8) << "否" << endl << "请输入选择：";
				cin >> choice5;
				if (choice5 == "否")
					break;
			}
			cout << endl;
			cout << "*********所有观影人的信息如下**********" << endl;
			
			for (int i = 0; i < 100; i++)
			{
				if (!CusInfo[i]._name.empty())
				{
					cout << "姓名：" << CusInfo[i]._name << endl << "性别：" << CusInfo[i]._sex << endl << "身份证号码：" << CusInfo[i]._IDnumber << endl << "年龄：" << CusInfo[i]._age <<'\n'<< endl;
				}
			}
			seat1.Showseats();
		}

	}
	//delete CusInfo;
	return 0;
}
