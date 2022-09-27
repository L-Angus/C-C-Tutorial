/*************************************************************************
	> File Name: pointer01.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 22:15:39 2022
 ************************************************************************/

#include<stdio.h>

int main(){
	float a = 1.4;
	//int *p1;
	unsigned char* p1;
	p1 = &a;
	printf("the p1 is %x\n", *p1);

	return 0;

}
