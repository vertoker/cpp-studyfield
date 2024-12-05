#include <iostream>

int main()
{
    int counter = 50, sum = 0;
    while (counter <= 100)
    {
        sum += counter;
        ++counter;
    }
    std::cout << "Result is " << sum << std::endl;
    return 0;
}