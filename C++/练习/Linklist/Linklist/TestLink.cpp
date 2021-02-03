#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"
//#include<windows.h>
#include <afx.h>
#include<cstring>
//--5.1--�����źſ�--�ڵ����ݽṹ
typedef struct _NETGRID_SIGNAL_LIBRARY_NODE
{

	unsigned int	ASID;				//������ź�������� 
	unsigned int	CREATEDATE;			//�ź������������ں�ʱ��
	unsigned int	ASCODE;				//������ı�� 
	unsigned int	SSID;				//�ź��������--���Ա�10
	double			FREQ;				//�ź�����Ƶ�� 
	unsigned int	SSTATUS;			//�ź�ʱ�������� 01-�����ź�, 02-�ǳ����ź�, 03-��ʧ�ź� 
	unsigned int	SPROPERTY;			//�ź�����: 01-��֪�źţ�̨վ���ݿ⣨A�⣩,02-��֪�źţ�̨վ���ݿ⣨B�⣩,03-��֪�źţ�δ��̨վ���ݿ�, 04-δ֪�źţ������źţ�, 05-�Ƿ��ź�, 06-Υ���ź�, 07-����ź�, 08-�����ź� 
	unsigned int	ISSTANDARD;			//�Ƿ��׼Ƶ�� : 00-�Ǳ�׼, 01-��׼
	double			MAXBANDWIDTH;		//���ռ�ô��� 
	double			MAXAMPLITUDE;		//����ƽ
	double			MIDAMPLITUDE;		//��ƽ��ֵ
	unsigned int	MODULATION;			//���Ʒ�ʽ, �����RMBT_CODE_ MODULATION ��CODE_ID�� 
	unsigned int	MODVALUE;			//������/����Ƶƫ/��ƫ/������� 
	char			ORGNAME[64];		//̨վ���뵥λ����
	char			STATIONUSER[64];	//̨վ��̨��λ���� 
	unsigned int	LONGITUDE;			//̨վ���侭�� 
	unsigned int	LATITUDE;			//̨վ����γ��
	char			STATIONNAME[64];	//̨վ����
	char			STATIONADDRESS[64];	//̨վ��ַ

	struct _NETGRID_SIGNAL_LIBRARY_NODE  *next;
} NETGRID_SIGNAL_LIBRARY_NODE;//Ƶ�ʷ����--��������ʱ�����ı��ļ���ȡ�������--����ί��ķ����׼��ȡ��ȡ--�Լ��ض�Ƶ�ʱ�--�������ݿ��ȡ

void myRead_Excel_For_SignalLib(NETGRID_SIGNAL_LIBRARY_NODE * pMySigLib)
{
	//--��01��--���洢����ʼ����--ɾ������

	NETGRID_SIGNAL_LIBRARY_NODE *pLIB = pMySigLib;
	while (pLIB->next != NULL)
	{
		NETGRID_SIGNAL_LIBRARY_NODE *pNode = pLIB->next;
		pLIB->next = pLIB->next->next;
		delete pNode;
	}
	pMySigLib->next = NULL;

	//--��02��--���ļ�·����--
	FILE *pF = NULL;
	char buf[1024], buf2[1024], colstr[256];
	char FilePath[255];
	GetCurrentDirectory(255, buf);
	sprintf_s(FilePath, 255, "%s\\Rmbt_Mcenter_Signa.csv", buf);
	pF = fopen(FilePath, "r");
	if (pF == NULL)
	{
		//sprintf(colstr, "ERROR#10352\n\t��<Rmbt_Mcenter_Signa.csv>�ļ�ʧ��, ErrorCode = %d", GetLastError());
		//TRACE(colstr);
		//DestroyList(pMySigLib);
		return;
	}
	CString str;

	pLIB = pMySigLib;	//�½ڵ�Append������ڵ�֮��
	int rows = 0;
	while (fgets(buf, 511, pF))
	{
		rows++;
		if (rows == 1)		continue;
		NETGRID_SIGNAL_LIBRARY_NODE *pNew = new NETGRID_SIGNAL_LIBRARY_NODE;	//ʹ������ʵ��--��ȡ֮��ִ������
		memset(pNew, 0, sizeof(NETGRID_SIGNAL_LIBRARY_NODE));
		pNew->next = NULL;
		strncpy(buf2, buf, 511);
		char *pStart = buf;
		char *pEnd = strchr(buf, ',');		//��ʼ����
		int curBytes = strlen(buf);
		int strPOS, endPos, rtn;
		char *pSTR;

		for (long i = 0; i < 19; ++i) //19��
		{
			if (i > 0)
			{
				pStart = &pEnd[1];
				pEnd = strchr(pStart, ','); if (pEnd == NULL) pEnd = &buf[curBytes];
			}
			endPos = (unsigned int)pEnd - (unsigned int)buf;
			buf2[endPos] = '\0';
			strPOS = (unsigned int)pStart - (unsigned int)buf;	//��ǰ�д�����ʼ�±�
			pSTR = &buf2[strPOS];	//��ǰ�д�
			colstr[0] = '\0';
			if (strlen(pSTR) > 0) rtn = sscanf(pSTR, "%s", colstr);	//��ȡ�д�								
			str = colstr;

			//Ŀǰ����¼ȡʱ��������Ƶ�㣬���������ȡ�ƽ�����ȡ�̨վ���ƣ�ӵ�������Ƶ�7�ֲ���
			if (i == 4)
				pNew->FREQ = (double)(1e6 * atof(str));
			else if (i == 5)
				pNew->SSTATUS = (unsigned int)(atoi(str));
			else if (i == 8)
				pNew->MAXBANDWIDTH = (double)(1e3 * atof(str));
			else if (i == 9)
				pNew->MAXAMPLITUDE = (double)(atof(str));
			else if (i == 10)
				pNew->MIDAMPLITUDE = (double)(atof(str));
			else if (i == 13)
				strcpy_s(pNew->ORGNAME, 62, str);
			else if (i == 17)
				strcpy_s(pNew->STATIONNAME, 62, str);
		}//for i

		pLIB->next = pNew;
		pLIB = pLIB->next;	//�����½ڵ㵽����

	}//while
	fclose(pF);

	return;
}

int main()
{
	NETGRID_SIGNAL_LIBRARY_NODE	*pMySigLib;

	pMySigLib = new NETGRID_SIGNAL_LIBRARY_NODE;						//ʹ������ʵ��--��ȡ֮��ִ������
	memset(pMySigLib, 0, sizeof(NETGRID_SIGNAL_LIBRARY_NODE));
	pMySigLib->next = NULL;
	myRead_Excel_For_SignalLib(pMySigLib);
	/****************************************************************************************************/
	/* 					��������ȡƵ��ľ�����Ϣ														*/
	/* 1- �ж�Ƶ���Ƿ����źű��У�����ڣ����ػ������ƺ͵�̨���ƣ�==>>>�ź����ͣ���ȨƵ�㣻��פ���źţ�	*/
	/* 2- �ж��Ƿ���Ͼ���������������ϣ��򷢳����棻													*/
	/* 3- �жϸ�Ƶ���Ƿ��Ѿ�����ǣ�������Ϊ����������������Ϣ��									*/
	/* 4- ����������������������������������������ʾ����Ƶ�ʣ�������ʱ�����������5�룻				*/
	/* 5- �źű���NETGRID_SIGNAL_LIBRARY_NODE	*pMySigLib;	//ʹ������ʵ��--��ȡ֮��ִ������������	*/
	/****************************************************************************************************/

}