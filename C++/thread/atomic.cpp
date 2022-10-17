/**
 * @file atomic.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * c++11提供了一个原子类型std::atomic<T>，通过这个原子类型管理的内部变量就可以称为原子变量。
 * 原子指的是一系列不可被 CPU 上下文交换的机器指令，这些指令组合在一起就形成了原子操作。在多核 
 * CPU 下，当某个 CPU 核心开始运行原子操作时，会先暂停其它 CPU 内核对内存的操作，以保证原子操作
 * 不会被其它 CPU 内核所干扰。
 *
 * 因为对原子变量进行的操作只能是一个原子操作（atomic operation），原子操作指的是不会被线程调度机制打断的操作，
 * 这种操作一旦开始，就一直运行到结束，中间不会有任何的上下文切换。
 * 多线程同时访问共享资源造成数据混乱的原因就是因为CPU的上下文切换导致的，使用原子变量解决了这个问题，因此互斥锁
 * 的使用也就不再需要了。
 *
 * atomic：默认无参构造，不允许拷贝；
 */

 // 多线程交替数数的计数器

/* 互斥锁版本 */
// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <atomic>
// #include <functional>

// struct Counter
// {
//     void increment() {
//         for (size_t i = 0; i < 10; i++) {
//             std::lock_guard<std::mutex> locker(m_mutex);
//             m_value++;
//             std::cout << "increment number: " << m_value << ", thread ID: " << std::this_thread::get_id() << std::endl;
//             std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         }
//     }

//     void decrement() {
//         for (size_t i = 0; i < 10; i++) {
//             std::lock_guard<std::mutex> locker(m_mutex);
//             m_value--;
//             std::cout << "decrement number: " << m_value << ", thread ID: " << std::this_thread::get_id() << std::endl;
//             std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         }
//     }

//     std::mutex m_mutex;
//     int m_value = 0;
// };

// int main()
// {
//     auto start = std::chrono::steady_clock::now();
//     Counter c;
//     auto increment = std::bind(&Counter::increment, &c);
//     auto decrement = std::bind(&Counter::decrement, &c);
//     std::thread t1(increment);
//     std::thread t2(decrement);
//     t1.join();
//     t2.join();
//     auto end = std::chrono::steady_clock::now();
//     auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//     std::cout << cost << " ms" << std::endl;
//     return 0;
// }

/* 原子变量版本 */
#include <iostream>
#include <thread>
#include <atomic>
#include <functional>
#include <chrono>

struct Counter
{
    void increment() {
        for (size_t i = 0; i < 10; i++) {
            m_value++;
            std::cout << "increment number: " << m_value << ", thread ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void decrement() {
        for (size_t i = 0; i < 10; i++) {
            m_value--;
            std::cout << "decrement number: " << m_value << ", thread ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    std::atomic_int m_value = 0;
};

int main()
{
    auto start = std::chrono::steady_clock::now();
    Counter c;
    auto increment = std::bind(&Counter::increment, &c);
    auto decrement = std::bind(&Counter::decrement, &c);
    std::thread t1(increment);
    std::thread t2(decrement);
    t1.join();
    t2.join();
    auto end = std::chrono::steady_clock::now();
    auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << cost << " ms" << std::endl;
    return 0;
}
