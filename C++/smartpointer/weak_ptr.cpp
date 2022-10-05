/*
weak_ptr可以看成是shared_ptr的助手，不管理shared_ptr内部的指针。
它没有重载操作符*和->，不共享指针，不操作资源，不增加计数，析构也不减少计数。
主要的作用是作为一个旁观者监视shared_ptr中管理的资源是否存在。

use_count: 返回计数；
expired: 判断观测的资源是否已经被释放；
lock: 用来获取管理所监测资源的shared_ptr对象
*/

#include <iostream>
#include <memory>

struct Test : public std::enable_shared_from_this<Test>
{
    std::shared_ptr<Test> getSharedPtr() {
        // return std::shared_ptr<Test>(this);
        return shared_from_this();
    }
    ~Test() { std::cout << "class Test is disstruct ... " << std::endl; }
};

struct TA;
struct TB;

struct TA
{
    std::weak_ptr<TB> bptr;
    ~TA() {
        std::cout << "class TA is disstruct ..." << std::endl;
    }
};

struct TB
{
    std::shared_ptr<TA> aptr;
    ~TB() {
        std::cout << "class TB is disstruct ..." << std::endl;
    }
};

void testPtr()
{
    std::shared_ptr<TA> ap(new TA);
    std::shared_ptr<TB> bp(new TB);
    std::cout << "TA object use_count: " << ap.use_count() << std::endl;
    std::cout << "TB object use_count: " << bp.use_count() << std::endl;

    ap->bptr = bp;
    bp->aptr = ap;

    std::cout << "TA object use_count: " << ap.use_count() << std::endl;
    std::cout << "TB object use_count: " << bp.use_count() << std::endl;

}


int main()
{
    // std::shared_ptr<int> sp(new int(10));
    // std::weak_ptr<int> wp1;
    // std::weak_ptr<int> wp2(wp1);
    // std::weak_ptr<int> wp3(sp);
    // std::weak_ptr<int> wp4;
    // wp4 = sp;
    // std::weak_ptr<int> wp5 = wp3;

    // std::cout << "use_count: " << std::endl;
    // std::cout << "wp1: " << wp1.use_count() << std::endl;
    // std::cout << "wp2: " << wp2.use_count() << std::endl;
    // std::cout << "wp3: " << wp3.use_count() << std::endl;
    // std::cout << "wp4: " << wp4.use_count() << std::endl;
    // std::cout << "wp5: " << wp5.use_count() << std::endl;

    // std::shared_ptr<int> shared(new int(10));
    // std::weak_ptr<int> weak(shared);
    // std::cout << "1.weak " << (weak.expired() ? "is" : "is not") << " expired" << std::endl;
    // // std::cout << weak.expired() << std::endl;
    // shared.reset();
    // std::cout << "2.weak " << (weak.expired() ? "is" : "is not") << " expired" << std::endl;

    // lock
    // std::shared_ptr<int> sp1, sp2;
    // std::weak_ptr<int> wp;

    // sp1 = std::make_shared<int>(520);
    // wp = sp1;
    // sp2 = wp.lock();
    // std::cout << "use_count: " << wp.use_count() << std::endl;

    // sp1.reset();
    // std::cout << "use_count: " << wp.use_count() << std::endl;

    // sp1 = wp.lock();
    // std::cout << "use_count: " << wp.use_count() << std::endl;

    // std::cout << "*sp1:" << *sp1 << std::endl;
    // std::cout << "*sp2:" << *sp2 << std::endl;

    // std::shared_ptr<Test> sp1(new Test);
    // std::cout << "use count: " << sp1.use_count() << std::endl;
    // std::shared_ptr<Test> sp2 = sp1->getSharedPtr();
    // std::cout << "use count: " << sp1.use_count() << std::endl;

    /* 循环引用 */
    testPtr();
    return 0;
}