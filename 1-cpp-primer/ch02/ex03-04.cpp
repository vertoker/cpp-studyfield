#include <iostream>

int main()
{
    // unsigned = unsigned int
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    // int = signed int
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    // errors next
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    char c1 = 10;
    int i1 = 300;
    std::cout << c1 + i1 << std::endl;

    return 0;
}