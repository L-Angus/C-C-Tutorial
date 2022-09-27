/*************************************************************************
	> File Name: pointer04.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 12:50:54 2022
 ************************************************************************/

#include<stdio.h>

int main()
{	
	int a = 1025;
	int *p;
	p = &a;
	printf("Size of integer is %d bytes\n", sizeof(int));
	printf("Address = %d, value = %d\n", p, *p);
	char* p0;
	p0 = (char *)p;
	printf("Size of char is %d bytes\n", sizeof(char));
	printf("Address = %d, value = %d\n", p0, *p0);
	printf("p0+1 value = %d\n",*(p0+1));
	return 0;
}
