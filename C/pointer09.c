/*************************************************************************
	> File Name: pointer09.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 22:24:44 2022
 ************************************************************************/

#include<stdio.h>

int Add(int a, int b){
	return a+b;
}

int main()
{
	int (*p)(int, int);
	p = Add;
	//printf("%d\n", Add);
	int c = (p)(2,3);
	printf("c = %d\n", c);
	return 0;
}
