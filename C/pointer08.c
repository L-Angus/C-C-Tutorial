/*************************************************************************
	> File Name: pointer08.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 22:06:18 2022
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void printHelloWorld(){
	printf("Hello world\n");
}

int *Add(int *a, int *b){
	int *c = (int *)malloc(sizeof(int));
	*c = (*a)+(*b);
	return c;
}

int main(){
	int a = 2, b=4;
	int *ptr = Add(&a, &b);
	printHelloWorld();
	printf("ptr = %d\n", *ptr);
	return 0;
}
