#include <iostream>

int main()
{
    int num1 = 0, num2 = 0;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    try
    {
        if (num2 == 0)
            throw std::runtime_error("Divide by zero");
        std::cout << "num1 / num2 = " << num1 / num2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}