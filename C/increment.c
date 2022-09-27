/*************************************************************************
	> File Name: increment.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 13:25:44 2022
 ************************************************************************/

#include<stdio.h>

void Increment(int *num){
	*num += 1;
}

int main(void)
{
	int a;
	a = 10;
	int *pointer = &a;
	Increment(pointer);
	printf("a = %d\n", a);
	return 0;
}
