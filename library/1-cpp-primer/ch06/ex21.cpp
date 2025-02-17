#include <iostream>

int max(int a, int* b)
{
    return a > *b ? a : *b;
}

int main()
{
    int a = 5, b = 6;
    int* p = &b;
    
    std::cout << max(a, p) << std::endl;
    return 0;
}