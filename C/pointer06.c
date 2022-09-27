/*************************************************************************
	> File Name: pointer06.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 四  9/22 20:45:17 2022
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int A[] = {2,4,5,8,1};
	int *p = A;
	printf("address = %d, value = %d\n", p, *p);
	p++;
	printf("address = %d, value = %d\n", p, *p);
	/*for(int i = 0; i < 5; i++){
		printf("address = %d\n", &A[i]);
		printf("address = %d\n", A+i);

		printf("value = %d\n", A[i]);
		printf("value = %d\n", *(A+i));
	}*/
	return 0;
}
