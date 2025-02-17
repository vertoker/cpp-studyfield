#include <iostream>

int abs(int i) { return i > 0 ? i : -i; }

int main()
{
    int input;
    std::cout << "Enter number: ";
    std::cin >> input;

    std::cout << "Absolute number: " << abs(input) << std::endl;
    return 0;
}