/*************************************************************************
	> File Name: pointer02.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 22:30:51 2022
 ************************************************************************/

#include<stdio.h>

int main()
{
	char* p = "hello world!\n";

	printf("The one is %x\n", *p);
	*p = 'a';
	printf("the %s\n", p);
	return 0;
}
