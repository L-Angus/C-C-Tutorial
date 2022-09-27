/*************************************************************************
	> File Name: const_cast.cpp
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 一  9/26 14:31:35 2022
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	const int val = 100;
//	auto n = const_cast<int>(val);
	int *p = const_cast<int *>(&val);
	*p = 200;
	std::cout << val << std::endl;
	std::cout << &val << std::endl;
	std::cout << *p << std::endl;
	return 0;
}
