#include <iostream>

int main()
{
    int grade;
    std::cout << "Enter grade: ";
    std::cin >> grade;

    std::cout << "variant 1: ";
    std::cout << ((grade > 90) ? "high pass" 
        : (grade > 75) ? "pass" 
        : (grade > 60) ? "min pass" : "fail");
    std::cout << std::endl;

    std::cout << "variant 2: ";
    if (grade > 90)
        std::cout << "high pass";
    else if (grade > 75)
        std::cout << "pass";
    else if (grade > 60)
        std::cout << "min pass";
    else std::cout << "fail";
    std::cout << std::endl;

    // variant 1 is more compact and more readable, but
    // with complex if statements, I'd prefer to use variant 2

    return 0;
}