#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"
//#include<windows.h>
#include <afx.h>
#include<cstring>
//--5.1--基本信号库--节点数据结构
typedef struct _NETGRID_SIGNAL_LIBRARY_NODE
{

	unsigned int	ASID;				//监控中信号样本编号 
	unsigned int	CREATEDATE;			//信号样本制作日期和时间
	unsigned int	ASCODE;				//监控中心编号 
	unsigned int	SSID;				//信号样本编号--来自表10
	double			FREQ;				//信号中心频率 
	unsigned int	SSTATUS;			//信号时域特征： 01-常发信号, 02-非常发信号, 03-消失信号 
	unsigned int	SPROPERTY;			//信号性质: 01-已知信号，台站数据库（A库）,02-已知信号，台站数据库（B库）,03-已知信号，未入台站数据库, 04-未知信号（不明信号）, 05-非法信号, 06-违规信号, 07-虚假信号, 08-其它信号 
	unsigned int	ISSTANDARD;			//是否标准频点 : 00-非标准, 01-标准
	double			MAXBANDWIDTH;		//最大占用带宽 
	double			MAXAMPLITUDE;		//最大电平
	double			MIDAMPLITUDE;		//电平均值
	unsigned int	MODULATION;			//调制方式, 外键，RMBT_CODE_ MODULATION （CODE_ID） 
	unsigned int	MODVALUE;			//波特率/正负频偏/相偏/调幅深度 
	char			ORGNAME[64];		//台站申请单位名称
	char			STATIONUSER[64];	//台站设台单位名称 
	unsigned int	LONGITUDE;			//台站发射经度 
	unsigned int	LATITUDE;			//台站发射纬度
	char			STATIONNAME[64];	//台站名称
	char			STATIONADDRESS[64];	//台站地址

	struct _NETGRID_SIGNAL_LIBRARY_NODE  *next;
} NETGRID_SIGNAL_LIBRARY_NODE;//频率分配表--运行启动时，从文本文件读取这个参数--将无委会的分配标准读取进取--以及特定频率表--随后从数据库读取

void myRead_Excel_For_SignalLib(NETGRID_SIGNAL_LIBRARY_NODE * pMySigLib)
{
	//--【01】--【存储区初始化】--删除链表

	NETGRID_SIGNAL_LIBRARY_NODE *pLIB = pMySigLib;
	while (pLIB->next != NULL)
	{
		NETGRID_SIGNAL_LIBRARY_NODE *pNode = pLIB->next;
		pLIB->next = pLIB->next->next;
		delete pNode;
	}
	pMySigLib->next = NULL;

	//--【02】--【文件路径】--
	FILE *pF = NULL;
	char buf[1024], buf2[1024], colstr[256];
	char FilePath[255];
	GetCurrentDirectory(255, buf);
	sprintf_s(FilePath, 255, "%s\\Rmbt_Mcenter_Signa.csv", buf);
	pF = fopen(FilePath, "r");
	if (pF == NULL)
	{
		//sprintf(colstr, "ERROR#10352\n\t打开<Rmbt_Mcenter_Signa.csv>文件失败, ErrorCode = %d", GetLastError());
		//TRACE(colstr);
		//DestroyList(pMySigLib);
		return;
	}
	CString str;

	pLIB = pMySigLib;	//新节点Append到这个节点之后
	int rows = 0;
	while (fgets(buf, 511, pF))
	{
		rows++;
		if (rows == 1)		continue;
		NETGRID_SIGNAL_LIBRARY_NODE *pNew = new NETGRID_SIGNAL_LIBRARY_NODE;	//使用链表实现--读取之后执行排序！
		memset(pNew, 0, sizeof(NETGRID_SIGNAL_LIBRARY_NODE));
		pNew->next = NULL;
		strncpy(buf2, buf, 511);
		char *pStart = buf;
		char *pEnd = strchr(buf, ',');		//开始条件
		int curBytes = strlen(buf);
		int strPOS, endPos, rtn;
		char *pSTR;

		for (long i = 0; i < 19; ++i) //19列
		{
			if (i > 0)
			{
				pStart = &pEnd[1];
				pEnd = strchr(pStart, ','); if (pEnd == NULL) pEnd = &buf[curBytes];
			}
			endPos = (unsigned int)pEnd - (unsigned int)buf;
			buf2[endPos] = '\0';
			strPOS = (unsigned int)pStart - (unsigned int)buf;	//当前列串的起始下标
			pSTR = &buf2[strPOS];	//当前列串
			colstr[0] = '\0';
			if (strlen(pSTR) > 0) rtn = sscanf(pSTR, "%s", colstr);	//获取列串								
			str = colstr;

			//目前仅仅录取时域特征、频点，带宽、最大幅度、平均幅度、台站名称，拥有者名称等7种参数
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
		pLIB = pLIB->next;	//连接新节点到链表

	}//while
	fclose(pF);

	return;
}

int main()
{
	NETGRID_SIGNAL_LIBRARY_NODE	*pMySigLib;

	pMySigLib = new NETGRID_SIGNAL_LIBRARY_NODE;						//使用链表实现--读取之后执行排序！
	memset(pMySigLib, 0, sizeof(NETGRID_SIGNAL_LIBRARY_NODE));
	pMySigLib->next = NULL;
	myRead_Excel_For_SignalLib(pMySigLib);
	/****************************************************************************************************/
	/* 					函数：获取频点的警告信息														*/
	/* 1- 判断频点是否在信号表中，如果在，返回机构名称和电台名称；==>>>信号类型：授权频点；常驻弱信号；	*/
	/* 2- 判断是否符合警告条件，如果符合，则发出警告；													*/
	/* 3- 判断该频点是否已经被标记，如果标记为噪声，则否决警告信息；									*/
	/* 4- 如果警告条件成立：：发出警告声；在主面板显示警告频率；发声的时间间隔必须大于5秒；				*/
	/* 5- 信号表在NETGRID_SIGNAL_LIBRARY_NODE	*pMySigLib;	//使用链表实现--读取之后执行排序！链表中	*/
	/****************************************************************************************************/

}