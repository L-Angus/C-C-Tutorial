/*************************************************************************
	> File Name: constructor.cpp
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 一  9/26 16:14:54 2022
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;


class Test{
	public:
		explicit Test(int num) : m_num(num){
			std::cout << "Construct " << m_num << std::endl;
		}
		Test(const Test& other) : m_num(other.m_num){
			std::cout << "Copy construct " << m_num << std::endl;
		}

		Test& operator=(const Test& other){
			std::cout << "Test operator" << std::endl;
			if(this == &other) return *this;
			m_num = other.m_num;
			return *this;
		}
		void Display(){
			std::cout << m_num << std::endl;
		}

		~Test(){
			std::cout << "Destroy " << m_num << std::endl;
		}
		int m_num;
};

int main()
{
	Test t(10);
	Test t2(t);
	Test t3 = t2;
	return 0;
}
