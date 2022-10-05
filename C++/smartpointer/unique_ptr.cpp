#include <iostream>
#include <memory>
#include <functional>

using namespace std;

std::unique_ptr<int> func() {
    return std::unique_ptr<int>(new int(520));
}

void deleteIntPtr(int* p) {
    delete p;
    std::cout << "release pointer p memory success..." << std::endl;
}

int main()
{
    std::unique_ptr<int> ptr1(new int(10));
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    // std::unique_ptr<int> ptr3 = func();
    ptr1.reset();
    ptr2.reset(new int(250));
    std::cout << *ptr2.get() << std::endl;

    // std::unique_ptr<int, void(*)(int*)> ptr3(new int(520), deleteIntPtr);
    // std::unique_ptr<int, std::function<void(int*)>> ptr3(new int(520), deleteIntPtr);
    std::unique_ptr<int, std::function<void(int*)>> ptr3(new int(520), [&](int* p) { delete p;});


    return 0;
}