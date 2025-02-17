#include <iostream>

int main()
{
    int x[10];
    int* p = x;

    std::cout << sizeof(x) / sizeof(*x) << std::endl; // sizeof array / sizeof int
    std::cout << sizeof(p) / sizeof(*p) << std::endl; // sizeof pointer / sizeof int

    return 0;
}