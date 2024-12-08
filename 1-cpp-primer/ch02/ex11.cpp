#include "ex11.hpp"

// Definition
void print1()
{
    std::cout << "print 1" << std::endl;
}

extern void print2();

extern int x;

int main()
{
    print1();
    print2();
    std::cout << x << std::endl;
    return 0;
}