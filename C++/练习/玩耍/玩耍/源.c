#include<stdio.h>
#include<stdlib.h>
int main() 
{ 
int i,j,k; 
for(i=1;i<=4;i++) //�ȴ�ӡ�ϱߵ����� 
{ 
for(j=1;j<=4-i;j++) //����Ҫ��ӡ�Ŀո����� 
printf(" "); 
for(k=1;k<=2*i-1;k++) //����Ҫ��ӡ���Ǻ��� 
printf("*"); 
printf("\n"); 
} 

for(i=1;i<=3;i++) 
{ 
for(j=1;j<=i;j++) //����Ҫ��ӡ�Ŀո��� 
printf(" "); 
for(k=1;k<=7-2*i;k++) //����Ҫ��ӡ���Ǻ��� 
printf("*"); 
printf("\n"); 
} 
system("pause");
return 0;
}