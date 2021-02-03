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




//指针第二种变为变量的方法:申请动态内存


struct Node* createList()
{
	//有表头链表：第一个表头不存数据
	//无表头链表：第一个表头存数据

	//产生一个结构体变量
	struct Node* ListHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//初始化一个结构体变量
	ListHeadNode->next = NULL;
	return ListHeadNode;
}
struct Node* createNode(struct student data)
{
	//有表头链表：第一个表头不存数据
	//无表头链表：第一个表头存数据

	//产生一个结构体变量
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	//初始化一个结构体变量
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//插入：插入信息
void InsertNodeByHead(struct Node* ListHeadNode, struct student data)
{
	//创建插入的新结点
	struct Node* newNode = createNode(data);
	//实现数据插入
	newNode->next = ListHeadNode->next;
	ListHeadNode->next = newNode;
}

//删除信息
void DeleNodeByName(struct Node* ListHeadNode, char* name)
{
	//删除节点
	struct Node* PosFrontNode = ListHeadNode;
	struct Node* PosNode = ListHeadNode->next;
	if (PosNode == NULL)
	{
		cout << "无法进行删除操作！" << endl;
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
				cout << "无相关内容，无法删除！" << endl;
				return;
			}
		}
		PosFrontNode->next = PosNode->next;
		free(PosNode);
	}
	return;
}

//查找信息
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

//打印当前节点数据
void printNode(struct Node* curNode)
{
	cout << "姓名\t学号\t年龄\t电话\t\t住址\n";
	cout << curNode->data.name << "\t" << curNode->data.number << "\t" << curNode->data.age << "\t" << curNode->data.tel << "\t" << curNode->data.addr;
}


//打印链表:浏览信息
void printList(struct Node* ListHeadNode)
{
	struct Node* pMove = ListHeadNode->next;
	cout << "姓名\t学号\t年龄\t电话\t\t住址\n";

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
	//把tempDate初始化为0
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
