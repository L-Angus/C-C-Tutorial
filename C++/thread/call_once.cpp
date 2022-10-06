/**
 * @file call_once.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * call_once: 在某些特定情况下，某些函数只能在多线程环境下调用一次。就可以调用call_once。
 * 使用call_once的时候，需要一个once_flag作为call_once的传入参数。
 * 多线程操作过程中，call_once内部的回调函数只会执行一次。
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::once_flag g_flag;

void do_once(int a, std::string b) {
    std::cout << "name: " << b << ", age: " << a << std::endl;
}

void do_something(int age, std::string name) {
    static int num = 1;
    std::call_once(g_flag, do_once, age, name);
    std::cout << "do something() function num = " << num++ << std::endl;
}

int main()
{
    std::thread t1(do_something, 20, "ace");
    std::thread t2(do_something, 20, "sabo");
    std::thread t3(do_something, 19, "luffy");
    t1.join();
    t2.join();
    t3.join();
    return 0;
}