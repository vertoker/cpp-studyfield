#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    // f(2.56, 42); // illegal
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}

void f()
{
    std::cout << "f()" << std::endl;
}
void f(int i)
{
    std::cout << "f(" << i << ")" << std::endl;
}
void f(int x, int y)
{
    std::cout << "f(" << x << ", " << y << ")" << std::endl;
}
void f(double x, double y)
{
    std::cout << "f(" << x << ", " << y << ")" << std::endl;
}
