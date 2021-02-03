#include<iostream>
#include<cstdio>
int main()
{
	char buf[100];
	memcpy(buf, 0, sizeof(buf));
	sprintf(buf, "%d",100);
	printf("%s",buf);
	/*char inputS[] = "10 3.14 hello";
	char outputS[50], x[10];
	int a;
	double b;
	sscanf(inputS,"%d%lf%s", &a, &b, x);
	printf("a is %d, b is %f, x is %s", a, b, x);
	sprintf(outputS, "a is %d, b is %f, x is %s", a, b, x);
	printf("%s\n", outputS);*/
	return 0;
}