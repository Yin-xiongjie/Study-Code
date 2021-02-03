#include<iostream>
#include"CharSz.h"

using namespace std;
int main()
{
	int cnt = 0;

	CharSZ de(7);   //除开'\0'只能存6个有效字符
	char* sz = "Hello";
	for (; cnt < strlen(sz) + 1; cnt++)
	{
		de[cnt] = sz[cnt];
	}
	for (cnt = 0; cnt < de.GetLen(); cnt++)
	{
		cout << de[cnt];
	}
	cout << endl;
	return 0;
}