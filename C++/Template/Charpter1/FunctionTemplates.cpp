/**
 * @file FunctionTemplates.cpp
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 * 函数模板(Function Templates)
 * 函数模板是被参数化的函数，是一组具有相似行为的函数。
 */

 /*
    函数模板提供了适用于不同数据类型的函数行为。也就是说，函数模板代表的是一组函数。
    语法:
    template<由逗号分隔的模板参数>
 */

#include <iostream>
#include <string>
#include <type_traits>

 // template<typename T>
 // T max(T a, T b) {
 //     return b < a ? a : b;
 // }

 // template<typename T>
 // T max(const T& a, const T& b) {
 //     return b < a ? a : b;
 // }

 /*
    1、模板两阶段编译检查:
     1. 在模板定义阶段，模板的检查不包含类型参数的检查:
         语法检查，比如少了分号；
         使用了未定义的不依赖与模板参数的名称（类型名，函数名，....）;
         未使用模板参数的static assertions;

     2. 在模板实例化阶段，为确保所有代码都是有效的，模板会再次检查，尤其是哪些依赖于类型参数的部分。

    2、编译和连接：
     两阶段的编译检查给模板处理带来了一个问题：当实例化一个模板的时候，编译器必须看到完整的定义。
     简单解决方法：将模板的声明和实现都写在头文件里。

    3、参数类型的推断：模板参数是由传递的调用参数决定的。

    4、类型推断中的类型转换：
     1.如果调用参数是按引用传递的，任何类型转换都不被允许；通过模板类型参数T定义的两个参数实参必须完全相同。
     2.如果调用蚕食按值传递的，那么只有退化是被允许的，const 和 volatile限制符会被忽略，引用被转换成被引用的类型，
     raw array和函数被转换为相应的指针类型。通过模板类型参数T定义的两个参数，它们实参的类型在退化(decay) 后必须一样。


    5、模板的默认参数，必须给模板类型参数也声明一个默认参数。
    template<typename T>
    void f(T = "");
    f(); // ERROR

    template<typename T = std::string>
    void f(T = "");
    f(); // OK

    6、多个模板参数
    多个参数函数模板，当应该返回另一个类型的值的时候，返回值会被做类型转换。
    解决方法：
    1. 引入第三个模板参数作为返回类型；template<typename T1, typename T2, typename RT> RT max(T1 a, T2 b);
    2. 让编译器找出返回类型；template<typename T1, typename T2> auto max(T1 a, T2 b);
    3. 将返回类型定义为两个参数类型的“公共类型”。std::common_type<>::type
 */

template<typename T>
void foo(T t) {
    // undeclared(); // 如果 undeclared()未定义，第一阶段就会报错，因为与模板参数无关
    // undeclared(t); //如果 undeclared(t)未定义，第二阶段会报错，因为与模板参数有关
    // static_assert(sizeof(int) > 10, "int too small"); // 与模板参数无关，总是报错
    // static_assert(sizeof(T) > 10, "T too small"); //与模板参数有关，只会在第二阶段报错
}

// template<typename RT, typename T1, typename T2>
// RT max(T1 a, T2 b) {
//     return b > a ? b : a;
// }

template<typename T1, typename T2>
auto max(T1 a, T2 b) {
    return b > a ? b : a;
}

template<typename T1, typename T2>
auto Max(T1 a, T2 b) ->decltype(true ? a : b) {
    return b > a ? b : a;
}

template<typename T1, typename T2>
auto Max2(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type {
    return b > a ? b : a;
}

template<typename T1, typename T2>
std::common_type_t<T1, T2> Max3(T1 a, T2 b) {
    return b > a ? b : a;
}

int main()
{
    // int i = 42;
    // std::cout << "max(7, i) = " << ::max(7, i) << std::endl; // 全局作用域限制符::
    // double f1 = 3.4;
    // double f2 = -6.7;
    // std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    // std::string s1 = "mathematics";
    // std::string s2 = "math";
    // std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
    auto res = ::Max3(12, 7.2);
    std::cout << typeid(res).name() << ":" << res << std::endl;

    return 0;
}