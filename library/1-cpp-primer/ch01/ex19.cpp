#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Enter number 1: " << std::flush;
    std::cin >> num1;
    std::cout << "Enter number 2: " << std::flush;
    std::cin >> num2;

    if (num1 < num2)
        std::cout << "Min is number 1: " << num1 << std::endl;
    if (num1 > num2)
        std::cout << "Min is number 2: " << num2 << std::endl;
    else
        std::cout << "Numbers are equal: " << num1 << std::endl;
    return 0;
}