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
	cout << "���������ѡ�";
	cin >> userkey;
	switch (userkey)
	{
	case 0:
		cout << "�˳�ϵͳ" << endl;
		system("pause");
		exit(0);
		break;
	case 1:
		cout << "������Ϣ" << endl;
		cout << "������ѧ����Ϣ" << endl;
		cout << "������";
		cin >> tempdata_1.name;
		cout << endl;
		cout << "ѧ�ţ�";
		cin >> tempdata_1.number;
		cout << endl;
		cout << "���䣺";
		cin >> tempdata_1.age;
		cout << endl;
		cout << "�绰��";
		cin >> tempdata_1.tel;
		cout << endl;
		cout << "��ַ��";
		cin >> tempdata_1.addr;
		cout << endl;
		InsertNodeByHead(List, tempdata_1);
		break;
	case 2:
		cout << "�����Ϣ" << endl;
		printList(List);
		break;
	case 3:
		cout << "ɾ����Ϣ" << endl;
		cout << "Ҫɾ����ѧ��������";
		cin >> tempdata_1.name;
		DeleNodeByName(List, tempdata_1.name);
		break;
	case 4:
		cout << "�޸���Ϣ" << endl;
		cout << "����Ҫ�޸ĵ�ѧ��:";
		cin >> tempdata_1.number;
		if (searchNodeNum(List, tempdata_1.number) == NULL)
		{
			cout << "δ�ҵ�������Ϣ" << endl;
		}
		else
		{
			struct Node*curNode = searchNodeNum(List, tempdata_1.number);
			cout << "**********�������µ�ѧ����Ϣ**********" << endl;
			cout << "������";
			cin >> curNode->data.name;
			cout << endl;
			cout << "ѧ�ţ�";
			cin >> curNode->data.number;
			cout << endl;
			cout << "���䣺";
			cin >> curNode->data.age;
			cout << endl;
			cout << "�绰��";
			cin >> curNode->data.tel;
			cout << endl;
			cout << "��ַ��";
			cin >> curNode->data.addr;
			cout << endl;
		}
		break;
	case 5:
		cout << "������Ϣ" << endl;
		cout << "����Ҫ���ҵ�ѧ��:";
		cin >> tempdata_1.number;
		if (searchNodeNum(List, tempdata_1.number) == NULL)
		{
			cout << "δ�ҵ�������Ϣ" << endl;
		}
		else
		{
			printNode(searchNodeNum(List, tempdata_1.number));
		}
		break;
	default:
		cout << "�������" << endl;
		break;
	}
}

//ϵͳ�˵�
void systemmenu()
{
	cout << "           ***************************************************				" << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *               ��ӭʹ��ѧ����Ϣ����ϵͳ          *             " << endl;
	cout << "           *    1.����ѧ����Ϣ             2.���ѧ����Ϣ    *             " << endl;
	cout << "           *    3.ɾ��ѧ����Ϣ             4.�޸�Ա����Ϣ    *             " << endl;
	cout << "           *    5.����ѧ����Ϣ             0.�˳�ϵͳ        *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           *                    �������ѡ��                 *             " << endl;
	cout << "           *                                                 *             " << endl;
	cout << "           ***************************************************             " << endl;
	cout << "������0-5" << endl;
}
