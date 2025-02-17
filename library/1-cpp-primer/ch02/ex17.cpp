#include <iostream>

int main()
{
    int i, &ri = i; // i is undefined
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl; // "10 10"
    return 0;
}