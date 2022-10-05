#ifndef COUNTEDOBJECT_H_
#define COUNTEDOBJECT_H_

class CountedObject {
public:
    CountedObject();
    ~CountedObject();
    enum { NumTruns = 5 };
    static int getCount() { return m_count; }
    static int m_count;
    static const int num = 1000;
    static const double number;
    int m;
};


#endif