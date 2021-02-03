#include"math.h"
typedef int DataType;

/****** 链表存储结构 ******/
typedef struct Node
{
	DataType data;									// data域用于存储数据元素
	struct Node *next;								// next域用于存放指向其后继的指针
}LNode, *PNode, *LinkList;							// LinkList为头指针

													/****** 初始化链表 （教材算法2-9）******/
int InitLinkList(LinkList *head)
{
	*head = (LinkList)malloc(sizeof(LNode));		// 申请内存空间，生成头结点
	if (!head)
	{
		printf("初始化链表错误!\n");
		return 0;
	}
	(*head)->next = NULL;							// 头结点的指针域为空
	return 1;
}

/****** 求链表长度 （教材算法2-10）******/
int LinkListLength(LinkList head)						// head为指向单链表的指针
{
	int length = 0;
	PNode p = head->next;

	while (p)										// 遍历单链表
	{
		length++;									// 链表长度增加一
		p = p->next;								// 指针后移
	}
	return length;
}

/****** 判断链表是否为空 （教材算法2-11）******/
int LinkListEmpty(LinkList head)						// head为指向单链表的指针
{
	if (head->next)									// 头结点指针域为空
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/****** 向链表插入新元素 （教材算法2-12）******/
int LinkListInsert(LinkList h, int pos, DataType x)		// h为指向单链表的指针，pos为插入位置，x为待插入数据元素
{
	PNode p = h, q;
	int i = 0;										// 计数器
	while (p && i < pos - 1)							// 指针后移，寻找待插入结点的前驱
	{
		p = p->next;								// 指针后移
		i++;										// 计数器加一
	}
	if (!p || i > pos - 1)							// 检查插入位置是否在链表中
	{
		printf("插入位置不合法!\n");
		return 0;
	}
	q = (PNode)malloc(sizeof(LNode));				// 生成新的结点
	if (!q)											// 检查新结点是否生成
	{
		printf("不能生成新结点\n");
		return 0;
	}
	q->data = x;									// 将待插入元素存入q结点的data域
	q->next = p->next;								// 使q结点的指针域指向p结点的后继
	p->next = q;									// 使p结点的指针指向q结点

	return 1;
}

/****** 按位置从链表删除元素 （教材算法2-13）******/
int LinkListDelete(LinkList h, int pos, DataType *item)					// h为指向单向链表的指针，pos为删除位置，item用于返回被删除结点的前驱
{
	PNode p = h, q;
	int i = 0;
	while (p->next && i < pos - 1)					// 寻找被删结点的前驱
	{
		p = p->next;
		i++;
	}
	if (!p->next || i > pos - 1)					// 检查待删除元素的位置是否在链表内
	{
		printf("删除位置不合法!\n");
		return 0;
	}
	q = p->next;									// 删除
	p->next = q->next;
	*item = q->data;									// 返回被删结点
	free(q);										// 释放被删除结点
	return 1;
}

/****** 从链表查询元素位置  （教材算法2-14）******/
int LinkNodeFind(LinkList h, DataType item)					// h为指向单链表的指针，item为待查的数据元素
{
	int pos = 1;
	PNode p = h->next;
	while (p && p->data != item)					// 查找
	{
		pos++;
		p = p->next;
	}
	return pos;										// 返回元素所在的位置
}

/****** 按位置从链表获取元素 （教材算法2-15）******/
void GetLinkElem(LinkList h, int pos)					// h为指向单链表的指针，pos为指定位置，item用于返回数据元素值
{
	int i = 0, item;
	PNode p = h->next;
	while (p && i < pos - 1)						// 从头结点开始寻找
	{
		i++;
		p = p->next;
	}
	if (!p || i > pos - 1)							// 未找到
	{
		printf("位置参数不合法!\n");
	}
	else
	{
		item = p->data;								// 找到并返回
		printf("查询的值为:%d", item);
	}
}

/****** 销毁链表 （教材算法2-16）******/
void DestroyLinkList(LinkList h)						// h为指向单链表的指针
{
	PNode p = h->next;
	while (h)
	{
		p = h;
		h = h->next;
		free(p);
	}
}

/****** 遍历链表 （教材算法2-17）******/
void TraverseLinkList(LinkList h)						// h为指向单链表的指针
{
	PNode p = h->next;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/****** 将整型数据按数位倒序存储在单链表中 ********/
void StoreNo(int NumIn, LinkList h)
{
	int temp, i;
	DataType x;
	int dig = floor(log10(NumIn)) + 1;		// 求输入的整型数一共有多少位
	temp = NumIn;
	for (i = dig; i > 0; i--)				// 处理每个数位的数
	{
		x = temp / pow(10, i - 1);			// 计算本轮最高位数字
		LinkListInsert(h, 1, x);			// 把当前数位的数字插入到单链表，用的头插法
		temp = temp % (int)pow(10, i - 1);	// 计算本轮余数，作为下一轮计算最高位数字的输入
	}
}
