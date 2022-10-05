/**
 * @file chrono.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-05
 *
 * @copyright Copyright (c) 2022
 *
 * c++11 提供了日期和时间相关的库：chrono。通过该库可以很方便的处理日期和时间，主要包括了三种类型的类：
 * 时间间隔：duration、时钟：clocks、时间点：time point。
 * duration：表示一段时间，用来记录时间长度，可以表示秒、分钟、小时的时间间隔。
 * duration原型
 * template<class Rep, class Period = std::ratio<1>> class duration;
 * template<std::intmax_t Num, std::intmax_t Denom = 1> class ratio;
 * -----------------------------------------------------------------
 * time_point类
 * Clock: 此时间点在此时钟上计量
 * Duration: 用于计量从纪元起时间的std::chrono::duration类型
 * -----------------------------------------------------------------
 * system_clock: 系统的时钟，系统的时间可以修改，甚至可以网络对时，因此系统时间差可能不准；
 * steady_clock: 是固定的时钟，相当于秒表，开始计时后，时间只会增长不能修改，适合用于记录程序耗时；
 * high_resolution_clock: 是时钟类steady_clock的别名，二者等价。
 * duration_cast: 通过这个函数可以对 duration 类对象内部的时钟周期 Period，和周期次数的类型 Rep 进行修改;
 * time_point_cast:函数的作用是对时间点进行转换，因为不同的时间点对象内部的时钟周期 Period，
 * 和周期次数的类型 Rep 可能也是不同的，一般情况下它们之间可以进行隐式类型转换，也可以通过该函数显示的进行转换;
 */

#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

using Clock = std::chrono::high_resolution_clock;
using Ms = std::chrono::milliseconds;
using Sec = std::chrono::seconds;

template<class Duration>
using TimePoint = std::chrono::time_point<Clock, Duration>;

void f() {
    std::cout << "print 1000 stars ..." << std::endl;
    for (size_t i = 0; i < 1000; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void print_ms(const TimePoint<Ms>& time_point) {
    std::cout << time_point.time_since_epoch().count() << " ms\n";
}



int main()
{
    // std::chrono::hours h(1);
    // std::cout << "duration: " << h.count() << std::endl;
    // std::chrono::milliseconds ms{ 3 };
    // std::cout << "duration: " << ms.count() << std::endl;
    // std::chrono::duration<int, std::ratio<1000>> ks(3);
    // std::cout << ks.count() << std::endl;
    // std::chrono::duration<double> dd(6.6);
    // std::cout << dd.count() << std::endl;
    // std::chrono::duration<double, std::ratio<1, 30>> hz(3.5);
    // std::cout << hz.count() << std::endl;

    // std::chrono::milliseconds ms{ 3 };
    // std::chrono::microseconds us = 2 * ms;
    // std::chrono::duration<double, std::ratio<1, 30>> hz(3.5);
    // std::cout << "3ms duration has " << ms.count() << " ticks\n"
    //     << "6000 us duration has " << us.count() << " ticks\n"
    //     << "3.5 hz duration has " << hz.count() << " ticks\n";

    // std::chrono::minutes t1(10);
    // std::chrono::seconds t2(60);
    // std::chrono::seconds t3 = t1 - t2;
    // std::cout << t3.count() << " seconds" << std::endl;

    // std::chrono::duration<double, std::ratio<9, 7>> d1(3);
    // std::chrono::duration<double, std::ratio<6, 5>> d2(1);
    // auto d3 = d1 - d2;
    // std::cout << typeid(d3).name() << std::endl;
    // std::cout << d3.count() << std::endl;

    // using namespace std::chrono;
    // typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
    // time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
    // std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

    // auto now = system_clock::now();
    // std::cout << typeid(now).name() << std::endl;
    // std::time_t last = system_clock::to_time_t(now - hours(24));
    // auto next = system_clock::to_time_t(now + hours(24));

    // std::cout << "One day ago, the time was " << std::put_time(std::localtime(&last), "%F %T") << '\n';
    // std::cout << "Next day, the time is " << std::put_time(std::localtime(&next), "%F %T") << '\n';

    // system_clock::time_point epoch;
    // duration<int, std::ratio<60 * 60 * 24>> day(1);
    // system_clock::time_point ppt(day);
    // using dday = duration<int, std::ratio<60 * 60 * 24>>;
    // time_point<system_clock, dday> t(dday(10));
    // auto today = system_clock::now();
    // time_t tm = system_clock::to_time_t(today);
    // std::cout << "今天的日期是: " << ctime(&tm);
    // time_t tm1 = system_clock::to_time_t(today + day);
    // std::cout << "明天的日期是: " << ctime(&tm1) << std::endl;
    // time_t tm2 = system_clock::to_time_t(epoch);
    // std::cout << "新纪元时间: " << ctime(&tm2) << std::endl;
    // time_t tm3 = system_clock::to_time_t(ppt);
    // std::cout << "新纪元时间天: " <<   ctime(&tm3) << std::endl;
    // time_t tm4 = system_clock::to_time_t(t);
    // std::cout << "新纪元时间天: " <<   ctime(&tm4) << std::endl;

    // auto start = std::chrono::steady_clock::now();
    // f();
    // auto last = std::chrono::steady_clock::now();
    // auto dt = last - start;
    // std::cout << "total cost: " << dt.count() << " ns" << std::endl;
    // auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt);
    // std::cout << "took: " << total_ms.count() << " ms" << std::endl;
    // std::chrono::duration<double, std::ratio<1, 1000>> func_ms = dt;
    // std::cout << "or: " << func_ms.count() << " ms" << std::endl;
    TimePoint<Sec> time_point_sec(Sec(6));
    TimePoint<Ms> time_point_ms(time_point_sec);
    print_ms(time_point_ms);

    time_point_ms = TimePoint<Ms>(Ms(6789));
    // TimePoint<Sec> sec(time_point_ms); error
    time_point_sec = std::chrono::time_point_cast<Sec>(time_point_ms);
    print_ms(time_point_sec);
    return 0;
}