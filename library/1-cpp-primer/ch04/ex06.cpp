#include <iostream>

int main()
{
    int input;
    std::cout << "Enter int: ";
    std::cin >> input;

    std::cout << "Entered number is ";
    std::cout << ((input % 2 == 0) ? "even" : "odd");
    std::cout << std::endl;
    return 0;
}