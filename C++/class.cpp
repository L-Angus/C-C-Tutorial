/*************************************************************************
	> File Name: class.cpp
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 一  9/26 16:00:46 2022
 ************************************************************************/

#include<iostream>
using namespace std;


class Outer
{
	class Inner{
		public:
			void func(){
				std::cout << "Inner func..." << std::endl;
			}
	};
	public:
		Inner obj;
		void func(){
			std::cout << "Outer func..." << std::endl;
			obj.func();
		}
};

int main()
{
	Outer o;
	o.func();
	return 0;
}
