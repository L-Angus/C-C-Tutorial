#include <iostream>
#include "CountedObject.h"
#include <string>
#include <cstdio>

int main()
{
    // std::cout << CountedObject::m_count << std::endl;
    // CountedObject co1;
    // std::cout << CountedObject::m_count << std::endl;
    // CountedObject* co2 = new CountedObject();
    // std::cout << CountedObject::m_count << std::endl;
    // delete co2;
    // std::cout << CountedObject::getCount() << std::endl;
    // std::cout << CountedObject::num << std::endl;
    // std::cout << CountedObject::number << std::endl;
    CountedObject co1, co2;
    std::cout << co1.CountedObject::NumTruns << std::endl;
    printf("%p\n", co1.CountedObject::NumTruns);
    printf("%p\n", co2.CountedObject::NumTruns);
    return 0;
}