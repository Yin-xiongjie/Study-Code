#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<cmath>


using namespace std;
struct student
{
	char* name;
	char number[11];
	int age;
	char tel[20];
	char addr[20];
};
struct Node
{
	struct student data;
	struct Node* next;

};




//ָ��ڶ��ֱ�Ϊ�����ķ���:���붯̬�ڴ�


struct Node* createList()
{
	//�б�ͷ������һ����ͷ��������
	//�ޱ�ͷ������һ����ͷ������

	//����һ���ṹ�����
	struct Node* ListHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//��ʼ��һ���ṹ�����
	ListHeadNode->next = NULL;
	return ListHeadNode;
}
struct Node* createNode(struct student data)
{
	//�б�ͷ������һ����ͷ��������
	//�ޱ�ͷ������һ����ͷ������

	//����һ���ṹ�����
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	//��ʼ��һ���ṹ�����
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//���룺������Ϣ
void InsertNodeByHead(struct Node* ListHeadNode, struct student data)
{
	//����������½��
	struct Node* newNode = createNode(data);
	//ʵ�����ݲ���
	newNode->next = ListHeadNode->next;
	ListHeadNode->next = newNode;
}

//ɾ����Ϣ
void DeleNodeByName(struct Node* ListHeadNode, char* name)
{
	//ɾ���ڵ�
	struct Node* PosFrontNode = ListHeadNode;
	struct Node* PosNode = ListHeadNode->next;
	if (PosNode == NULL)
	{
		cout << "�޷�����ɾ��������" << endl;
		return;
	}
	else
	{
		while (strcmp(PosNode->data.name, name))
		{
			PosFrontNode = PosNode;
			PosNode = PosFrontNode->next;
			if (PosNode == NULL)
			{
				cout << "��������ݣ��޷�ɾ����" << endl;
				return;
			}
		}
		PosFrontNode->next = PosNode->next;
		free(PosNode);
	}
	return;
}

//������Ϣ
struct Node* searchNodeNum(struct Node*	ListHeadNode, char* number)
{
	struct Node* pMove = ListHeadNode->next;
	if (pMove == NULL)
	{
		return pMove;
	}
	else
	{
		while (strcmp(pMove->data.number, number))
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				break;
			}
		}
		cout << endl;
		return pMove;
	}
}

//��ӡ��ǰ�ڵ�����
void printNode(struct Node* curNode)
{
	cout << "����\tѧ��\t����\t�绰\t\tסַ\n";
	cout << curNode->data.name << "\t" << curNode->data.number << "\t" << curNode->data.age << "\t" << curNode->data.tel << "\t" << curNode->data.addr;
}


//��ӡ����:�����Ϣ
void printList(struct Node* ListHeadNode)
{
	struct Node* pMove = ListHeadNode->next;
	cout << "����\tѧ��\t����\t�绰\t\tסַ\n";

	while (pMove)
	{
		cout << pMove->data.name << "\t" << pMove->data.number << "\t" << pMove->data.age << "\t" << pMove->data.tel << "\t" << pMove->data.addr << endl;
		pMove = pMove->next;
	}
	cout << endl;
}

/*void readInfo(char *file, struct Node* ListHeadNode)
{
   FILE *fp = fopen(file, "r");
   if (fp == NULL)
   {
	fp = fopen(file, "w");
   }
   struct student tempDate;
   while(fscanf(fp,"%s\t%s\t%d\t%s\t%s\n", tempDate.name,tempDate.number,
				&tempDate.age,tempDate.tel,tempDate.addr)!=EOF)
   {
	InsertNodeByHead(ListHeadNode,tempDate);
	//��tempDate��ʼ��Ϊ0
	memset(&tempDate,0,sizeof(tempDate));
   }
   fclose(fp);
}

void saveInfo(char *file,struct Node* ListHeadNode)
{
	FILE *fp = fopen(file, "w");
	struct Node* pMove = ListHeadNode->next;

	while (pMove)
	{
		fprintf(fp,"%s\t%s\t%d\t%s\t%s\n", pMove->data.name,pMove->data.number,
				&pMove->data.age,pMove->data.tel,pMove->data.addr);
		pMove = pMove->next;
	}
	fclose(fp);
}
*/
