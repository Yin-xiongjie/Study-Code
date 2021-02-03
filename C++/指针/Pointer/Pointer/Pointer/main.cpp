#include<stdio.h>
#include<Windows.h>

/************
指针详讲

指针的三个层次 
①基本使用
②指向数组的指针
③函数指针
*************/

int main(void)
{
	//第一个层次：基本使用
/*******************
	int area = 257; //房子面积257平

	char* p;  //定义一个指向char类型的指针变量
	p = (char*)&area; 

	printf("%d\n", *p);
********************/


	//第二层次：指向数组的指针
	int arry[10] = {11,22,33,44,55,66,77,88,99,100};
	int (*arry_1)[10];
	arry_1 = &arry;

	for (int i = 0; i < 10; i++)
	{
		//第一种输出
		//printf("第%d个数：%d\n", i, (*arry_1)[i]);

		//第二种输出
		printf("第%d个数：%d\n", i, arry_1[0][i]);
	}

	system("pause");
	return 0;

}