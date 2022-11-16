#include <iostream>
#include <string>

template<typename T>
T max(T a, T b)
{
    // 如果b < a, 返回a，否则返回b
    return b < a ? a : b;
}

int main() {
    int i = 42;
    std::cout << "max(7,i):" << ::max(7, i) << std::endl;
    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << '\n';
    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "max(s1,s2): " << ::max(s1, s2) << std::endl;
    return 0;
}