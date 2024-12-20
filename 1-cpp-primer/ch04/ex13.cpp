#include <iostream>

int main()
{
    int i;
    double d;

    d = i = 3.5; // d = 3, i = 3
    std::cout << i << ' ' << d << std::endl;
    i = d = 3.5; // i = 3, d = 3.5
    std::cout << i << ' ' << d << std::endl;
    return 0;
}