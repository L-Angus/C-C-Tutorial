/**
 * @file mutex.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * mutex: 解决多线程数据混乱的方案是进行线程同步，最常用的就是互斥锁。
 * std::mutex: 独占的互斥锁，不能递归使用；
 * std::timed_mutex: 带超时的独占互斥锁，不能递归使用；
 * std::recursive_mutex: 递归互斥锁，不带超时功能；
 * std::recursive_timed_mutex: 带超时的递归互斥锁。
 *
 * std::mutex
 * lock(): 用于给临界区加锁，并且只能有一个线程获取锁的所有权。
 * void lock();
 * try_lock(): 获取互斥锁的所有权并对互斥锁加锁。
 * bool try_lock();
 * 二者区别在于try_lock不阻塞线程，lock会阻塞线程。
 * 1. 如果互斥锁是未锁定状态，得到了互斥锁的所有权并加锁成功，函数返回true；
 * 2. 如果互斥锁是锁定状态，无法得到互斥锁的所有权，加锁失败，函数返回false。
 *
 * unlock：对加锁的线程进行解锁。
 *
 * 线程同步的目的是让多线程按照顺序依次执行临界区代码，这样做线程对共享资源的访问
 * 就从并行访问变为了线性访问，访问效率降低了，但是保证了数据的正确性。
 *
 * lock_guard: c++11新增的类，可以简化互斥锁lock和unlock的写法，同时也更安全。lock_guard使用RAII技术，
 * 就是在类构造函数中分配资源，在析构函数中释放资源，保证资源出了作用于就被释放。
 *
 * std::recursive_mutex: 允许同一线程多次获取互斥锁，可以用来解决同一线程需要多次获取互斥量死锁的问题。
 *
 * std::timed_mutex 是超时独占互斥锁，主要是在获取互斥锁资源时增加了超时等待功能，因为不知道获取锁资源需要等待多长时间，
 * 为了保证不一直等待下去，设置了一个超时时长，超时后线程就可以解除阻塞去做其他事情了。
 * std::timed_mutex 比 std::_mutex 多了两个成员函数：try_lock_for() 和 try_lock_until()：
 * try_lock_for 函数是当线程获取不到互斥锁资源的时候，让线程阻塞一定的时间长度;
 * try_lock_until 函数是当线程获取不到互斥锁资源的时候，让线程阻塞到某一个指定的时间点;
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int g_num = 0; // 为g_num_mutex所保护
std::mutex g_num_mutex;
std::timed_mutex g_mutex;

void slow_increment(int id) {
    for (size_t i = 0; i < 3; i++)
    {
        g_num_mutex.lock();
        ++g_num;
        std::cout << id << " ==> " << g_num << std::endl;
        g_num_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void slow_increment1(int id) {
    for (size_t i = 0; i < 3; i++)
    {
        // 使用lock_guard管理
        std::lock_guard<std::mutex> lock(g_num_mutex);
        ++g_num;
        std::cout << id << " ==> " << g_num << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

struct Calculate
{
    Calculate() : m_i(6) {}
    void mul(int x) {
        std::lock_guard<std::recursive_mutex> locker(m_mutex);
        m_i *= x;
    }

    void div(int x) {
        std::lock_guard<std::recursive_mutex> locker(m_mutex);
        m_i /= x;
    }

    void both(int x, int y) { // 死锁
        std::lock_guard<std::recursive_mutex> locker(m_mutex);
        mul(x);
        div(y);
    }

    int m_i;
    std::recursive_mutex m_mutex;
};

void work() {
    std::chrono::seconds timeout(1);
    while (true) {
        // 通过阻塞一定的时长来争取到互斥锁所有权
        if (g_mutex.try_lock_for(timeout)) {
            std::cout << "current thread ID: " << std::this_thread::get_id() << ", get mutex..." << std::endl;
            // 模拟处理任务用了一定的时长
            std::this_thread::sleep_for(std::chrono::seconds(10));
            g_mutex.unlock();
            break;
        }
        else {
            std::cout << "current thread ID: " << std::this_thread::get_id() << ", not get mutex..." << std::endl;
            // 模拟处理其他任务用了一定的时长
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}


int main()
{
    // std::thread t1(slow_increment1, 0);
    // std::thread t2(slow_increment1, 1);
    // t1.join();
    // t2.join();
    // Calculate cal;
    // std::cout << "cal.m_i = " << cal.m_i << std::endl;
    // cal.both(6, 3);
    // std::cout << "cal.m_i = " << cal.m_i << std::endl;
    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();
    return 0;
}
