#pragma once
#include<iostream>

using namespace std;
class CharSZ
{
private:
	int Len;
	char *pBuf;
public:

	int GetLen()
	{
		return Len;
	}
	CharSZ(int);
	~CharSZ();
	char& operator [](int i);
};

