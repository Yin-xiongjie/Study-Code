#define _CRT_SECURE_NO_WARNINGS
#include"singleList.h"
#include<iomanip>

void KeyDown();

void systemmenu();

struct Node* List = NULL;

int main()
{

	List = createList();
	//  readInfo(studen.txt, List);
	while (1)
	{
		systemmenu();
		KeyDown();
		system("pause");
		system("cls");
	}
	return 0;
}

void KeyDown()
{
	struct student tempdata_1;
	int userkey;
	cout << "请输入操作选项：";
	cin >> userkey;
	switch (userkey)
	{
	case 0:
		cout << "退出系统" << endl;
		system("pause");
		exit(0);
		break;
	case 1:
		cout << "插入信息" << endl;
		cout << "请输入学生信息" << endl;
		cout << "姓名：";
		cin >> tempdata_1.name;
		cout << endl;
		cout << "学号：";
		cin >> tempdata_1.number;
		cout << endl;
		cout << "年龄：";
		cin >> tempdata_1.age;
		cout << endl;
		cout << "电话：";
		cin >> tempdata_1.tel;
		cout << endl;
		cout << "地址：";
		cin >> tempdata_1.addr;
		cout << endl;
		InsertNodeByHead(List, tempdata_1);
		break;
	case 2:
		cout << "浏览信息" << endl;
		printList(List);
		break;
	case 3:
		cout << "删除信息" << endl;
		cout << "要删除的学生姓名：";
		cin >> tempdata_1.name;
		DeleNodeByName(List, tempdata_1.name);
		break;
	case 4:
		cout << "修改信息" << endl;
		cout << "输入要修改的学号:";
		cin >> tempdata_1.number;
		if (searchNodeNum(List, tempdata_1.number) == NULL)
		{
			cout << "未找到查找信息" << endl;
		}
		else
		{
			struct Node*curNode = searchNodeNum(List, tempdata_1.number);
			cout << "**********请输入新的学生信息**********" << endl;
			cout << "姓名：";
			cin >> curNode->data.name;
			cout << endl;
			cout << "学号：";
			cin >> curNode->data.number;
			cout << endl;
			cout << "年龄：";
			cin >> curNode->data.age;
			cout << endl;
			cout << "电话：";
			cin >> curNode->data.tel;
			cout << endl;
			cout << "地址：";
			cin >> curNode->data.addr;
			cout << endl;
		}
		break;
	case 5:
		cout << "查找信息" << endl;
		cout << "输入要查找的学号:";
		cin >> tempdata_1.number;
		if (searchNodeNum(List, tempdata_1.number) == NULL)
		{
			cout << "未找到查找信息" << endl;
		}
		else
		{
			printNode(searchNodeNum(List, tempdata_1.number));
		}
		break;
	default:
		cout << "输入错误！" << endl;
		break;
	}
}

//系统菜单
void systemmenu()
{
	cout << "           ***************************************************				" << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *               欢迎使用学生信息管理系统          *             " << endl;
	cout << "           *    1.插入学生信息             2.浏览学生信息    *             " << endl;
	cout << "           *    3.删除学生信息             4.修改员工信息    *             " << endl;
	cout << "           *    5.查找学生信息             0.退出系统        *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                    输入操作选项                 *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           ***************************************************             " << endl;
	cout << "请输入0-5" << endl;
}
