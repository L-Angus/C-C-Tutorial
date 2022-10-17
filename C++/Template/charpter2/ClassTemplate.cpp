#include <iostream>
#include <vector>
#include <cassert>
#include <string>

template<typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    void push(const T& elem);
    void pop();
    const T& top() const;
    bool empty() const { return elems.empty(); }
    int size() const { return elems.size(); }
};

template<typename T>
void Stack<T>::push(const T& elem) {
    elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T>
const T& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}

int main()
{
    Stack<int> IntStack;
    Stack<std::string> stringStack;
    IntStack.push(7);
    IntStack.push(3);
    std::cout << IntStack.top() << std::endl;
    stringStack.push("hello world!");
    std::cout << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << stringStack.size() << std::endl;
    Stack<std::pair< int, int>> ps;
    ps.push({ 4,5 });
    ps.push({ 6,7 });
    std::cout << ps.top().first << std::endl;
    std::cout << ps.top().second << std::endl;
    return 0;
}
