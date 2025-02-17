#include <iostream>

size_t factorial(size_t num)
{
    if (num < 2) return num;
    return num * factorial(num - 1);
}

int main()
{
    size_t input;
    std::cout << "Enter number: ";
    std::cin >> input;

    std::cout << "Factorial number: " << factorial(input) << std::endl;
    
    return 0;
}