#include <iostream>

int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    
    std::cout << sum << " = 0"; // not hard to compute
    return 0;
}