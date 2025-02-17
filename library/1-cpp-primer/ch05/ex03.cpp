#include <iostream>

int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    // better to read, easier to see things
    
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    return 0;
}