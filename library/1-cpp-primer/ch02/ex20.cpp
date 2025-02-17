#include <iostream>

int main()
{
    int i = 42;
    int *pi = &i;
    
    *pi = *pi * *pi; // tricky syntax
    // damn, I love shittiest C++ syntax

    // answer is 42 * 42 = 1764
    std::cout << *pi << " = " << 42 * 42 << std::endl;

    return 0;
}