// 9. Never call virtual functions during construction or destruction

#include <iostream>

class Base
{
public:
    Base() { f1(); }
    virtual ~Base() { f2(); }

    virtual void f1() { std::cout << "f1 base" << std::endl; }
    virtual void f2() { std::cout << "f2 base" << std::endl; }
    virtual void f3() { std::cout << "f3 base" << std::endl; }
    virtual void f4() { std::cout << "f4 base" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() : Base() { f3(); }
    ~Derived() { f4(); }

    void f1() override { std::cout << "f1 derived" << std::endl; }
    void f2() override { std::cout << "f2 derived" << std::endl; }
    void f3() override { std::cout << "f3 derived" << std::endl; }
    void f4() override { std::cout << "f4 derived" << std::endl; }
};

int main()
{
    Derived derived; // f1 and f2 called only Base:: versions

    return 0;
}