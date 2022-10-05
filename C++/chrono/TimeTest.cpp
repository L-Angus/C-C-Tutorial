#include "Timer.hpp"
#include <iostream>

void func() {
    std::cout << "hello world!" << std::endl;
}

int main()
{
    Timer t;
    func();
    std::cout << t.elapsed() << " ms" << std::endl;
    std::cout << t.elapsed_micro() << " us" << std::endl;
    std::cout << t.elapsed_nano() << " ns" << std::endl;
    std::cout << t.elapsed_seconds() << " s" << std::endl;
    std::cout << t.elapsed_minutes() << " min" << std::endl;
    std::cout << t.elapsed_hours() << " h" << std::endl;
    return 0;
}