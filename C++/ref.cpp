/*************************************************************************
	> File Name: ref.cpp
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 一  9/26 14:12:37 2022
 ************************************************************************/

#include<iostream>
using namespace std;

int a[] = {0,1,2,3,4};

int & index(int i){
	return a[i];
}

int main()
{
	index(3) = 100;
	std::cout << "a[3] = " << a[3] << std::endl;
	for(int i =0 ; i < 5; ++i){
		std::cout << a[i] << std::endl;	
	}
	return 0;
}
