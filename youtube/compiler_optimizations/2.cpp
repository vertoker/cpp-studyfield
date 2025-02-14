#include <iostream>

class A
{
public:
    A() { std::cout << "default" << std::endl; }
    A(const char*) { std::cout << "default char*" << std::endl; }
    A(const A&) { std::cout << "copy" << std::endl; }
    A(A&&) { std::cout << "move" << std::endl; }
};

class B
{
    A a;
public:
    B(A a) : a(std::move(a)) { }
};

int main()
{
    std::cout << "a" << std::endl;
    A a;
    std::cout << "b1" << std::endl;
    B b1(a);
    std::cout << "b2" << std::endl;
    B b2("Hi");
    std::cout << "b3" << std::endl;
    B b3(std::move(a));
    
    return 0;
}