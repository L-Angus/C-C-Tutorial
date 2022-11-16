#include <iostream>

int func(int a, int b){
    std::cout << "调用普通函数..." << std::endl;
    return a+b;
}

template <typename T>
T func(T a, T b){
    std::cout << "调用模板函数..." << std::endl;
    return a+b;
}

int main()
{
    int a = 1;
    int b = 1;
    double c = 1.1;
    double d = 2.2;
    std::cout << func(a, b) << std::endl;
    std::cout << func(c, d) << std::endl;
    return 0;
}