/**
 * @file aSync.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * 1. std::future: 因此多线程程序中的任务大都是异步的，主线程和子线程分别执行不同的任务，
 * 如果想要在主线中得到某个子线程任务函数返回的结果可以使用 C++11 提供的std:future类;
 * 2. std::promise:  是一个协助线程赋值的类，它能够将数据和 future 对象绑定起来，为获取
 * 线程函数中的某个值提供便利。
 *
 * promise的使用：
 * 1. 在主线程中创建std::promise对象；
 * 2. 将这个std::promise对象通过引用的方式传递给子线程的任务函数；
 * 3. 在子线程任务函数中给std::promise对象赋值；
 * 4. 在主线程中通过std::promise对象取出绑定的future实例对象；
 * 5. 通过得到的future对象取出子线程任务函数中返回的值。
 *
 * 3. std::packaged_task: 包装了一个可调用对象包装器类对象（可调用对象包装器包装的是可调用对象，
 * 可调用对象都可以作为函数来使用);
 * std::packaged_task, 其实就是对子线程要执行的任务函数进行了包装，和可调用对象包装器的使用方法相同，
 * 包装完毕之后直接将包装得到的任务对象传递给线程对象就可以了。
 *
 * 4. std::async: 可以直接创建子线程执行任务
 *
 *
 * 总结：
 * 1. 使用 std::async() 函数，是多线程操作中最简单的一种方式，不需要自己创建线程对象，并且可以得到子线程函数的返回值。
 * 2. 使用 std::promise 类，在子线程中可以传出返回值也可以传出其他数据，并且可选择在什么时机将数据从子线程中传递出来，使用起来更灵活。
 * 3. 使用 std::packaged_task 类，可以将子线程的任务函数进行包装，并且可以得到子线程的返回值。
 */


#include <iostream>
#include <thread>
#include <future>


int main()
{
    /* std::promise */
    // 1. 在主线程中创建std::promise对象；
    // std::promise<int> pr;
    // // 2. 将这个std::promise对象通过引用的方式传递给子线程的任务函数；
    // std::thread t1([](std::promise<int>& p) {
    //     // 3. 在子线程任务函数中给std::promise对象赋值；
    //     p.set_value(100);
    //     // p.set_value_at_thread_exit(100);
    //     std::this_thread::sleep_for(std::chrono::seconds(3));
    //     std::cout << "睡醒了..." << std::endl;
    //     }, std::ref(pr));
    // // 4. 在主线程中通过std::promise对象取出绑定的future实例对象；
    // std::future<int> f = pr.get_future();
    // // 5. 通过得到的future对象取出子线程任务函数中返回的值。
    // auto value = f.get();
    // std::cout << "value: " << value << std::endl;
    // t1.join();

    /* std::packaged_task */
    // std::packaged_task<int(int)> task([](int x) {
    //     return x += 100;
    //     });

    // std::thread t1(std::ref(task), 100);
    // std::future<int> f = task.get_future();
    // auto value = f.get();
    // std::cout << "value = " << value << std::endl;

    // t1.join();

    /* std::async */
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    // auto f = std::async([](int x) {
    //     std::cout << "Sub thread ID: " << std::this_thread::get_id() << std::endl;
    //     std::this_thread::sleep_for(std::chrono::seconds(10));
    //     return x += 100;
    //     }, 100);

    // std::future_status status;
    // do {
    //     status = f.wait_for(std::chrono::seconds(1));
    //     if (status == std::future_status::deferred) {
    //         std::cout << "线程还没执行..." << std::endl;
    //         f.wait();
    //     }
    //     else if (status == std::future_status::ready) {
    //         std::cout << "子线程返回值..." << f.get() << std::endl;
    //     }
    //     else if (status == std::future_status::timeout) {
    //         std::cout << "任务未执行完毕，继续等待..." << std::endl;
    //     }
    // } while (status != std::future_status::ready);
    auto f = std::async(std::launch::deferred, [](int x) {
        std::cout << "子线程ID: " << std::this_thread::get_id() << std::endl;
        return x += 100;
        }, 100);
    std::cout << "主线程开始休眠5秒..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << f.get() << std::endl;

    return 0;
}

