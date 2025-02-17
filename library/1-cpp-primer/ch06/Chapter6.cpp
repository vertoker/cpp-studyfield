#include "Chapter6.hpp"

size_t factorial(size_t num)
{
    if (num < 2) return num;
    return num * factorial(num - 1);
}

int abs2(int i) 
{
    return i > 0 ? i : -i;
}
