#include <iostream>
#include <memory>
#include <string>
#include <cstring>

class Test {
public:
    Test() { std::cout << "constructor test ..." << std::endl; }
    Test(int x) { std::cout << "constructor test, x = " << x << std::endl; }
    Test(const std::string& str) { std::cout << "constructor test, str = " << str << std::endl; }
    ~Test() { std::cout << "destructor test ..." << std::endl; }
};

void deleteIntPtr(int* p) {
    delete p;
    std::cout << "int内存被释放了..." << std::endl;
}

template <typename T>
std::shared_ptr<T> make_shared_array(size_t size) {
    return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

int main()
{
    // std::shared_ptr<Test> ptr = std::make_shared<Test>();
    // std::cout << "ptr use count = " << ptr.use_count() << std::endl;
    // std::shared_ptr<Test> ptr2 = std::make_shared<Test>(520);
    // std::cout << "ptr2 use count = " << ptr2.use_count() << std::endl;
    // auto ptr3 = std::make_shared<Test>("我是要成为海贼王的男人!!!");
    // std::cout << "ptr3 use count = " << ptr3.use_count() << std::endl;
    // ptr3.reset();
    // std::cout << "ptr3 use count = " << ptr3.use_count() << std::endl;
    // ptr3.reset(new Test("hello"));
    // std::cout << "ptr3 use count = " << ptr3.use_count() << std::endl;

    // 获取原始指针
    // int len = 128;
    // std::shared_ptr<char> sp(new char[len]);
    // char* add = sp.get();
    // memset(add, 0, len);
    // strcpy(add, "我要成为海贼王的男人");
    // std::cout << "string: " << add << std::endl;

    // std::shared_ptr<int> p(new int);
    // *p = 100;
    // std::cout << *p.get() << " " << *p << " " << p.get() << std::endl;

    // std::shared_ptr<int> ptr(new int(250), deleteIntPtr);
    // std::cout << ptr.use_count() << std::endl;
    // std::shared_ptr<Test> sp(new Test("hello world!"), [](Test* p) {delete p;});

    // std::shared_ptr<int> ptr(new int[10], std::default_delete<int[]>());
    // std::cout << ptr.use_count() << std::endl;

    // delete array
    auto ptr1 = make_shared_array<int>(100);
    std::cout << ptr1.use_count() << std::endl;
    auto ptr2 = make_shared_array<char>(128);
    std::cout << ptr2.use_count() << std::endl;
    return 0;
}