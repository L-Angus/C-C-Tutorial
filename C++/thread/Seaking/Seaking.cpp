#include <iostream>
#include <thread>
#include <list>
#include <chrono>
#include <mutex>

std::mutex mt;

class Seaking {
public:
    Seaking() {}
    ~Seaking() {}
    void makefriend() {
        for (size_t i = 0; i < 1000; i++) {
            // std::unique_lock<std::mutex> locker(mt);
            std::cout << "喜得一枚女票: " << i << std::endl;
            Sea.push_back(i);
        }
    }
    void breakup() {
        for (size_t i = 0; i < 1000; i++) {
            if (Sea.empty()) {
                std::cout << "end" << std::endl;
            }
            else {
                std::cout << "失去一妹女票~" << i << std::endl;
                Sea.pop_front();
            }
        }
    }

private:
    std::list<int> Sea;
};


int main()
{
    Seaking sea;
    auto now = std::chrono::steady_clock::now();
    // sea.makefriend();
    // sea.breakup();
    std::thread t1(&Seaking::makefriend, sea);
    std::thread t2(&Seaking::breakup, sea);
    t1.join();
    t2.join();
    auto end = std::chrono::steady_clock::now();
    auto cost = std::chrono::duration_cast<std::chrono::microseconds>(end - now).count();
    std::cout << cost << std::endl;
    return 0;
}