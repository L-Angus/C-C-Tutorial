#include <iostream>
#include "CountedObject.h"
#include <string>

int main()
{
    std::cout << CountedObject::m_count << std::endl;
    CountedObject co1;
    std::cout << CountedObject::m_count << std::endl;
    CountedObject* co2 = new CountedObject();
    std::cout << CountedObject::m_count << std::endl;
    delete co2;
    std::cout << CountedObject::getCount() << std::endl;
    std::cout << CountedObject::num << std::endl;

    return 0;
}