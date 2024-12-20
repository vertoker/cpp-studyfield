#include <iostream>

int main()
{
    int input;
    std::cin >> input;
    while (input != 42)
        std::cin >> input;
    
    return 0;
}