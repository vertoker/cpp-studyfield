#include <iostream>

// reference to ex09.cpp
int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;
    
    std::cout << "Result is " << sum << std::endl;
    return 0;
}