#include"math.h"
typedef int DataType;

/****** ����洢�ṹ ******/
typedef struct Node
{
	DataType data;									// data�����ڴ洢����Ԫ��
	struct Node *next;								// next�����ڴ��ָ�����̵�ָ��
}LNode, *PNode, *LinkList;							// LinkListΪͷָ��

													/****** ��ʼ������ ���̲��㷨2-9��******/
int InitLinkList(LinkList *head)
{
	*head = (LinkList)malloc(sizeof(LNode));		// �����ڴ�ռ䣬����ͷ���
	if (!head)
	{
		printf("��ʼ���������!\n");
		return 0;
	}
	(*head)->next = NULL;							// ͷ����ָ����Ϊ��
	return 1;
}

/****** �������� ���̲��㷨2-10��******/
int LinkListLength(LinkList head)						// headΪָ�������ָ��
{
	int length = 0;
	PNode p = head->next;

	while (p)										// ����������
	{
		length++;									// ����������һ
		p = p->next;								// ָ�����
	}
	return length;
}

/****** �ж������Ƿ�Ϊ�� ���̲��㷨2-11��******/
int LinkListEmpty(LinkList head)						// headΪָ�������ָ��
{
	if (head->next)									// ͷ���ָ����Ϊ��
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/****** �����������Ԫ�� ���̲��㷨2-12��******/
int LinkListInsert(LinkList h, int pos, DataType x)		// hΪָ�������ָ�룬posΪ����λ�ã�xΪ����������Ԫ��
{
	PNode p = h, q;
	int i = 0;										// ������
	while (p && i < pos - 1)							// ָ����ƣ�Ѱ�Ҵ��������ǰ��
	{
		p = p->next;								// ָ�����
		i++;										// ��������һ
	}
	if (!p || i > pos - 1)							// ������λ���Ƿ���������
	{
		printf("����λ�ò��Ϸ�!\n");
		return 0;
	}
	q = (PNode)malloc(sizeof(LNode));				// �����µĽ��
	if (!q)											// ����½���Ƿ�����
	{
		printf("���������½��\n");
		return 0;
	}
	q->data = x;									// ��������Ԫ�ش���q����data��
	q->next = p->next;								// ʹq����ָ����ָ��p���ĺ��
	p->next = q;									// ʹp����ָ��ָ��q���

	return 1;
}

/****** ��λ�ô�����ɾ��Ԫ�� ���̲��㷨2-13��******/
int LinkListDelete(LinkList h, int pos, DataType *item)					// hΪָ���������ָ�룬posΪɾ��λ�ã�item���ڷ��ر�ɾ������ǰ��
{
	PNode p = h, q;
	int i = 0;
	while (p->next && i < pos - 1)					// Ѱ�ұ�ɾ����ǰ��
	{
		p = p->next;
		i++;
	}
	if (!p->next || i > pos - 1)					// ����ɾ��Ԫ�ص�λ���Ƿ���������
	{
		printf("ɾ��λ�ò��Ϸ�!\n");
		return 0;
	}
	q = p->next;									// ɾ��
	p->next = q->next;
	*item = q->data;									// ���ر�ɾ���
	free(q);										// �ͷű�ɾ�����
	return 1;
}

/****** �������ѯԪ��λ��  ���̲��㷨2-14��******/
int LinkNodeFind(LinkList h, DataType item)					// hΪָ�������ָ�룬itemΪ���������Ԫ��
{
	int pos = 1;
	PNode p = h->next;
	while (p && p->data != item)					// ����
	{
		pos++;
		p = p->next;
	}
	return pos;										// ����Ԫ�����ڵ�λ��
}

/****** ��λ�ô������ȡԪ�� ���̲��㷨2-15��******/
void GetLinkElem(LinkList h, int pos)					// hΪָ�������ָ�룬posΪָ��λ�ã�item���ڷ�������Ԫ��ֵ
{
	int i = 0, item;
	PNode p = h->next;
	while (p && i < pos - 1)						// ��ͷ��㿪ʼѰ��
	{
		i++;
		p = p->next;
	}
	if (!p || i > pos - 1)							// δ�ҵ�
	{
		printf("λ�ò������Ϸ�!\n");
	}
	else
	{
		item = p->data;								// �ҵ�������
		printf("��ѯ��ֵΪ:%d", item);
	}
}

/****** �������� ���̲��㷨2-16��******/
void DestroyLinkList(LinkList h)						// hΪָ�������ָ��
{
	PNode p = h->next;
	while (h)
	{
		p = h;
		h = h->next;
		free(p);
	}
}

/****** �������� ���̲��㷨2-17��******/
void TraverseLinkList(LinkList h)						// hΪָ�������ָ��
{
	PNode p = h->next;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/****** ���������ݰ���λ����洢�ڵ������� ********/
void StoreNo(int NumIn, LinkList h)
{
	int temp, i;
	DataType x;
	int dig = floor(log10(NumIn)) + 1;		// �������������һ���ж���λ
	temp = NumIn;
	for (i = dig; i > 0; i--)				// ����ÿ����λ����
	{
		x = temp / pow(10, i - 1);			// ���㱾�����λ����
		LinkListInsert(h, 1, x);			// �ѵ�ǰ��λ�����ֲ��뵽�������õ�ͷ�巨
		temp = temp % (int)pow(10, i - 1);	// ���㱾����������Ϊ��һ�ּ������λ���ֵ�����
	}
}
