/**
 * @file this_thread.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * this_thread类
 * get_id(): 可以获取当前线程的ID。
 * sleep_for(): 线程创建后有五种状态：创建态、就绪态、运行态、阻塞态（挂起态）、退出态（终止态）。
 * 为了能够实现并发处理，多个线程都是分时复用CPU的时间片，快速的交替处理各个线程中的任务，因此多个
 * 线程之间需要争抢CPU时间片，捡到了就执行，抢不到则无法执行。
 * 命名空间this_thread中提供了一个睡眠函数sleep_for，调用这个函数线程会马上从运行态变成阻塞态。
 *
 * sleep_until(): 指定线程阻塞到某一个指定的时间点time_point类型，之后解除阻塞。
 * sleep_for(): 指定线程阻塞一定的时间长度duration类型，之后解除阻塞。
 * 两者的功能是相同的，只不过前者是基于时间点去阻塞，后者是基于时间段阻塞线程。
 *
 * yeild(): 调用此函数，处于运行态的线程会主动让出自己的CPU时间片，最终变成就绪态。
 * 线程调用了yeild函数会主动放弃CPU资源，但是这个变为就绪态的线程会马上参与到下一轮CPU的抢夺中，不排除
 * 它能继续抢到CPU时间片的情况，这是概率问题。
 * 结论：1. yeild函数的目的是避免一个线程长时间占用CPU资源，从而导致多线程处理性能下降。
 * 2. yeild函数是让当前线程主动放弃了当前自己抢到的CPU资源，但是在下一轮还会继续抢。
 */

#include <iostream>
#include <thread>
#include <chrono>

void func() {
    std::cout << "Sub thread: " << std::this_thread::get_id() << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Sub thread: " << std::this_thread::get_id() << ", i = " << i << std::endl;
    }

}

void func1() {
    for (size_t i = 0; i < 10; i++)
    {
        auto now = std::chrono::system_clock::now();
        std::chrono::seconds sec(2);
        std::this_thread::sleep_until(now + sec);
        std::cout << "Sub thread: " << std::this_thread::get_id() << ", i = " << i << std::endl;
    }

}

void func_yeild() {
    for (size_t i = 0; i < 10000000; i++)
    {
        std::cout << "Sub thread: " << std::this_thread::get_id() << ", i = " << i << std::endl;
        std::this_thread::yield();
    }
}

int main()
{
    std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
    std::thread t(func_yeild);
    std::thread t1(func_yeild);
    t.join();
    t1.join();
    return 0;
}