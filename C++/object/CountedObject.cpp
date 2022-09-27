#include "CountedObject.h"

int CountedObject::m_count = 0;

CountedObject::CountedObject() {
    ++m_count;
}

CountedObject::~CountedObject() {
    --m_count;
}
