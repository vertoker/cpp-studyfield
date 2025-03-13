// 7. Declare destructors virtual in polymorphic base classes

#include <memory>
#include <iostream>

class Base
{
public:
    Base(size_t size) : ptr{malloc(size)} { }
    virtual ~Base() { destroy(); } // is virtual

protected:
    // if require custom destructor, then use destructor function (name as you want)
    void destroy()
    {
        free(ptr);
    }

    void* ptr;
};

class Derived : public Base
{
public:
    // in type, can be unlimited non-repeated by signature constructors
    Derived(size_t size) : Base(size) { }

    // but in type, can be ONLY ONE destructor

    // ~Derived() override { } // no, several destructors => error
    // ~Derived() : Base() { } // no, several destructors => error

    ~Derived() { // only in that way it can
        destroy(); // call base destroy function
    }
    // virtual ~Derived() { } // yes, but only if it's not final class
};

int main()
{
    return 0;
}