#include <iostream>
#include <thread>

/*
C++11中提供的线程类叫做std::thread.
thread(); 默认构造
thread(thread&& other); 移动构造
template<class Funtion, class... Args>
explicit thread(Function&& f, Args&&... args); 多参数构造
thread(const thread& other) = delete; thread不可赋值

join: 主动等待线程的终止（线程阻塞）。该函数在哪个线程中调用，哪个线程就会被阻塞执行。例如在主函数中
子线程调用此函数，主线程会阻塞，子线程会继续执行。

detach: 函数的作用是进行线程分离，分离主线程和创建出的子线程。（孩子翅膀硬了，自己外出闯荡）

joinable: 用于判断主线程和子线程是否处理关联状态（join）：
返回值为true：主线程和子线程之间有关联关系；
返回值为false: 主线程和子线程之间没有关联关系。

线程不可赋值，可以移动。
*/

// get_id: 获取线程ID，每个线程都有一个唯一标识的ID，称为线程ID。
// std::thread::id get_id() const noexcept;

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void func(int num, const std::string& str) {
    for (size_t i = 0; i < num; i++) {
        std::cout << "thread ID: " << std::this_thread::get_id() << " sub thread: i = " << i << " num: " << num << ", str: " << str << std::endl;
    }
}

void func1() {
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "sub thread: i = " << i << std::endl;
    }

}

void download1() {
    // 模拟下载，总共耗时500ms，阻塞线程500ms
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "sub thread1: " << std::this_thread::get_id() << ", 找到历史正文..." << std::endl;
}

void download2() {
    // 模拟下载，总共耗时300ms，阻塞线程300ms
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "sub thread2: " << std::this_thread::get_id() << ", 找到历史正文..." << std::endl;
}

void doSomething() {
    std::cout << "集齐历史正文，呼叫罗兵..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "历史正文解析中..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "启航，前往拉夫德尔..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "找到OnePiece，成为海贼王，哈哈哈哈！！！" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "若干年后，草帽全员卒..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "大海贼王时代再次被开启..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::cout << "主线程的线程ID: " << std::this_thread::get_id() << std::endl;
    // std::thread t1(func, 10, "hello world!");
    // std::thread t2(func1);
    // std::cout << "t1 thread ID: " << t1.get_id() << std::endl;
    // std::cout << "t2 thread ID: " << t2.get_id() << std::endl;
    // t1.join();
    // t2.join();
    std::thread t1(download1);
    std::thread t2(download2);
    t1.join();
    t2.join();
    doSomething();
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::thread t;
    std::cout << "before starting, joinable: " << t.joinable() << std::endl;
    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() << std::endl;
    t.join();
    std::cout << "after starting, joinable: " << t.joinable() << std::endl;
    std::thread t1(foo);
    std::cout << "after starting, joinable: " << t1.joinable() << std::endl;
    t1.detach();
    std::cout << "after starting, joinable: " << t1.joinable() << std::endl;

    auto num = std::thread::hardware_concurrency();
    std::cout << "CPU number: " << num << std::endl;
    return 0;
}