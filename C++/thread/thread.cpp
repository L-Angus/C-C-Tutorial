#include <iostream>
#include <thread>

/*
C++11中提供的线程类叫做std::thread.
thread(); 默认构造
thread(thread&& other); 移动构造
template<class Funtion, class... Args>
explicit thread(Function&& f, Args&&... args); 多参数构造
thread(const thread& other) = delete; thread不可赋值
*/

// get_id: 获取线程ID，每个线程都有一个唯一标识的ID，称为线程ID。
// std::thread::id get_id() const noexcept;

#include <iostream>
#include <thread>
#include <chrono>

