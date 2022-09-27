#ifndef COUNTEDOBJECT_H_
#define COUNTEDOBJECT_H_

class CountedObject {
public:
    CountedObject();
    ~CountedObject();
    static int getCount() { return m_count; }
    static int m_count;
    static const int num = 1000;
    int m;
};


#endif