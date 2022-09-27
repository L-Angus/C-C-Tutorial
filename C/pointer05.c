/*************************************************************************
	> File Name: pointer05.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 13:07:20 2022
 ************************************************************************/

#include<stdio.h>

int main()
{
	int x = 6;
	int *p = &x;
	printf("x's value = %d\n", x);
	printf("address = %d, value = %d\n", p, *p);
	int **q;
	q = &p;
	printf("address = %d, value_top = %d, value_bottom = %d\n", q, *q, **q);
	int ***r;
	r = &q;
	printf("address = %d, value1 = %d, value2 = %d, value3 = %d\n", r, *r, **r, ***r);
	***r = 20;
	printf("x's value = %d\n", x);
	return 0;
}
