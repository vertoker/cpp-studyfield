#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r; // int
    auto b = ci; // int
    auto c = cr; // int
    auto d = &i; // int*
    auto e = &ci; // const int*
    auto& g = ci; // const int&

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << *d << std::endl;
    std::cout << *e << std::endl;
    std::cout << g << std::endl;

    a = 42; // a is int
    b = 42; // b is int
    c = 42; // c is int
    // d = 42; // 42 is not int*
    // e = 42; // 42 is not int* and e - const
    // g = 42; // g is const

    std::cout << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << *d << std::endl;
    std::cout << *e << std::endl;
    std::cout << g << std::endl;

    return 0;
} 