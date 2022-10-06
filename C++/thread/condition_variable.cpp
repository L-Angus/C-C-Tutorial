/**
 * @file condition_variable.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * 条件变量是 C++11 提供的另外一种用于等待的同步机制，它能阻塞一个或多个线程，
 * 直到收到另外一个线程发出的通知或者超时时，才会唤醒当前阻塞的线程。条件变量需要和互斥量配合起来使用，
 * C++11 提供了两种条件变量：
 * 1. condition_variable：需要配合 std::unique_lock<std::mutex> 进行 wait 操作，也就是阻塞线程的操作。
 * 2. condition_variable_any：可以和任意带有 lock()、unlock() 语义的 mutex 搭配使用，也就是说有四种：
 * (1).std::mutex：独占的非递归互斥锁;
 * (2).std::timed_mutex：带超时的独占非递归互斥锁;
 * (3).std::recursive_mutex：不带超时功能的递归互斥锁;
 * (4).std::recursive_timed_mutex：带超时的递归互斥锁.
 * =========================================================================
 * 条件变量通常用于生产者和消费者模型，过程如下：
 * 1. 拥有条件变量的线程获取互斥量；
 * 2. 循环检查某个条件，如果某个条件不满足阻塞当前线程，否则线程继续向下执行；
 * (1). 产品的数量达到上限，生产者阻塞，否则生产者一直生产。。。
 * (2). 产品的数量为0，消费者阻塞，否则消费者一直消费。。。
 * 3. 条件满足之后，可以调用notify_one()或者notify_all()唤醒一个或者所有被阻塞的线程：
 *  (1). 由消费者唤醒被阻塞的生产者，生产者解除阻塞继续生产。。。
 * (2). 由生产者唤醒被阻塞的消费者，消费者解除阻塞继续消费。。。
 * =========================================================================
 * condition_variable 的成员函数主要分为两部分：线程等待（阻塞）函数 和线程通知（唤醒）函数，
 * 这些函数被定义于头文件 <condition_variable>。
 * wait/wait_for/wait_until
 * notify_one/notify_all
 * notify_one()：唤醒一个被当前条件变量阻塞的线程
 * notify_all()：唤醒全部被当前条件变量阻塞的线程
 * =========================================================================
 * condition_variable_any 的成员函数也是分为两部分：线程等待（阻塞）函数 和线程通知（唤醒）函数，
 * 这些函数被定义于头文件 <condition_variable>。
 */

 /* 生产者和消费者模型 */

#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <functional>
#include <condition_variable>

class SyncQueue {
public:
    SyncQueue(int maxSize) : m_maxSize(maxSize) {
        std::cout << "[==== Sync Queue ====]" << std::endl;
    }
    bool empty() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool full() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    int size() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    void put(const int& x) {
        // std::unique_lock<std::mutex> locker(m_mutex);
        std::lock_guard<std::mutex> locker(m_mutex);
        // 判断任务列表是不是已经满了
        // while (m_queue.size() == m_maxSize) {
        //     std::cout << "任务列表已满，请耐心等待..." << std::endl;
        //     // 阻塞线程
        //     m_notFull.wait(locker);
        // }
        m_notFull.wait(m_mutex, [this]() {
            return m_queue.size() != m_maxSize;
            });
        // 将任务放入到任务列表中
        m_queue.push_back(x);
        std::cout << x << " 被生产" << std::endl;
        // 通知消费者去消费
        m_notEmpty.notify_one();
    }

    int take() {
        // std::unique_lock<std::mutex> locker(m_mutex);
        std::lock_guard<std::mutex> locker(m_mutex);
        // while (m_queue.empty()) {
        //     std::cout << "任务队列已空，请耐心等待..." << std::endl;
        //     m_notEmpty.wait(locker);
        // }
        m_notEmpty.wait(m_mutex, [this]() {
            return !m_queue.empty();
            });
        // 从任务列表取出任务（消费）
        int x = m_queue.front();
        m_queue.pop_front();
        // 通知生产者去生产
        m_notFull.notify_one();
        std::cout << x << " 被消费" << std::endl;
        return x;
    }

private:
    std::list<int> m_queue;
    int m_maxSize;
    std::mutex m_mutex; // 互斥量
    // std::condition_variable m_notEmpty; // 不为空的条件变量
    // std::condition_variable m_notFull; // 没有满的条件变量
    std::condition_variable_any m_notEmpty;
    std::condition_variable_any m_notFull;
};

int main()
{
    SyncQueue taskQ(50);
    auto producer = std::bind(&SyncQueue::put, &taskQ, std::placeholders::_1);
    auto consumer = std::bind(&SyncQueue::take, &taskQ);
    std::thread t1[3];
    std::thread t2[3];
    for (size_t i = 0; i < 3; i++) {
        t1[i] = std::thread(producer, i + 100);
        t2[i] = std::thread(consumer);
    }

    for (size_t i = 0; i < 3; i++)
    {
        t1[i].join();
        t2[i].join();
    }

    return 0;
}