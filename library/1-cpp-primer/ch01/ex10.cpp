#include <iostream>

int main()
{
    int counter = 10;
    while (counter >= 0)
    {
        std::cout << counter << std::endl;
        --counter;
    }
    return 0;
}