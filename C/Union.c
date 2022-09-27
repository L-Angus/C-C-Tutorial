/*************************************************************************
	> File Name: Union.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 一  9/26 12:51:52 2022
 ************************************************************************/

#include<stdio.h>

union Data{
	char a;
	short b;
	int c;

};

void test()
{
	union Data ob;
	ob.a = 10;
	ob.b = 20;
	ob.c = 30;
	printf("%d\n", ob.a+ob.b+ob.c);
}

int main()
{
	test();
	return 0;
}
