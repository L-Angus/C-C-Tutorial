/**
 * @file Timer.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-05
 *
 * @copyright Copyright (c) 2022
 *
 * 实现boost库Timer功能，用于函数耗时检测。
 */
#include <chrono>
#include <iostream>

template<class tp>
using TimePoint = std::chrono::time_point<tp>;

using HighResClock = std::chrono::high_resolution_clock;
using Ms = std::chrono::milliseconds;
using Us = std::chrono::microseconds;
using Ns = std::chrono::nanoseconds;

class Timer {
public:
    Timer() : m_begin(HighResClock::now()) {}
    void reset() { m_begin = HighResClock::now(); }
    template<typename Duration = Ms>
    int64_t elapsed() const {
        return std::chrono::duration_cast<Duration>(HighResClock::now() - m_begin).count();
    }
    int64_t elapsed_micro() const {
        return elapsed<Us>();
    }
    int64_t elapsed_nano() const {
        return elapsed<Ns>();
    }
    int64_t elapsed_seconds() const {
        return elapsed<std::chrono::seconds>();
    }
    int64_t elapsed_minutes() const {
        return elapsed<std::chrono::minutes>();
    }
    int64_t elapsed_hours() const {
        return elapsed<std::chrono::hours>();
    }
private:
    TimePoint<HighResClock> m_begin;
};
