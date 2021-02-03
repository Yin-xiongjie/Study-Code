#include<stdio.h>
#include<stdlib.h>
int main() 
{ 
int i,j,k; 
for(i=1;i<=4;i++) //先打印上边的四行 
{ 
for(j=1;j<=4-i;j++) //控制要打印的空格数量 
printf(" "); 
for(k=1;k<=2*i-1;k++) //控制要打印的星号数 
printf("*"); 
printf("\n"); 
} 

for(i=1;i<=3;i++) 
{ 
for(j=1;j<=i;j++) //控制要打印的空格数 
printf(" "); 
for(k=1;k<=7-2*i;k++) //控制要打印的星号数 
printf("*"); 
printf("\n"); 
} 
system("pause");
return 0;
}