#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i; // inner scope
    
    std::cout << i << std::endl; // 100
    std::cout << sum << std::endl; // 45
    
    return 0;
}