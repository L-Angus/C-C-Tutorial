#include <iostream>
template <typename T3, typename T1, typename T2>
T3 funcT(T1 a, T2 b){
    return a+b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto res = funcT<double, double, int>(3.3, 4);
    std::cout << "res: " << res << std::endl;
    return 0;
}
