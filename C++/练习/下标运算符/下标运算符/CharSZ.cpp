#include "CharSZ.h"



CharSZ::CharSZ(int l)
{
	Len = l;
	pBuf = new char[Len];
}

CharSZ::~CharSZ()
{
	delete[] pBuf;
}

char& CharSZ::operator [](int i)
{
	static char def = '\0';
		if (i < Len&&i >= 0)
		{
			return pBuf[i];
		}
		else
		{
			cout << "下标越界" << endl;
			return def;
		}
}


