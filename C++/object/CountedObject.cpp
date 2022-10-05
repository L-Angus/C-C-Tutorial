#include "CountedObject.h"

int CountedObject::m_count = 0;
const double CountedObject::number = 32.4;

CountedObject::CountedObject() {
    ++m_count;
}

CountedObject::~CountedObject() {
    --m_count;
}
