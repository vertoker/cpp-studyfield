#include <iostream>

struct A
{
    int a;
};
struct B : A
{
    int b;
};

int main()
{
    B obj1;
    obj1.b = 2;
    obj1.a = 1;

    A obj2 = obj1;
    // B obj3 = obj2; // not allowed

    std::cout << obj1.a << obj1.b << std::endl;
    std::cout << obj2.a << std::endl;
    
    return 0;
}