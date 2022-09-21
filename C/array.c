#include <stdio.h>

int main()
{
    int arr[10];
    printf("sizeof(arr) = %ld %ld\n", sizeof(arr), 10 * sizeof(int));
    int b[] = { 1,2,3 };
    printf("sizeof(b) = %ld\n", sizeof(b));
    return 0;
}