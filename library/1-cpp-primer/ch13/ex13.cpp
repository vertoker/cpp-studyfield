#include <iostream>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "default ctor" << std::endl; }
    X(const X&) { std::cout << "copy ctor" << std::endl; }
    X& operator=(const X&) { std::cout << "copy assignment" << std::endl; return *this; }
    ~X() { std::cout << "default dtor" << std::endl; }
};

void f(const X& rx, X x)
{
    std::cout << "f" << std::endl;
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}

int main()
{
    X *px = new X;
    f(*px, *px);
    std::cout << "end f" << std::endl;
    delete px;
    std::cout << "end main" << std::endl;

    return 0;
}