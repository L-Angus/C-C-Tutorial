/*************************************************************************
	> File Name: pointer03.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 23:02:26 2022
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int a = 0x12345678;
	int b = 0x99991199;
	
	int *p1 = &b;
	char* p2 = (char*)&b;
	printf("the p1+1 is %x, %x, %x\n", *(p1+1), p1[1], *p1+1);
	printf("the p2+1 is %x\n", *p2);
	return 0;
}
