#include <iostream>
#include <string>

int main()
{
    std::string requestToContinue;

    do
    {
        std::string str1, str2;
        std::cout << "Enter first string: ";
        std::cin >> str1;
        std::cout << "Enter second string: ";
        std::cin >> str2;

        if (str1 < str2)
            std::cout << "First string " << str1 << " is less that second " << str2 << std::endl;
        else if (str1 > str2)
            std::cout << "Second string " << str2 << " is less that first " << str1 << std::endl;
        else std::cout << "Both strings " << str1 << " and " << str2 << " has the same length" << std::endl;

        std::cout << "Want to continue? (y, n): ";
        std::cin >> requestToContinue;
    } while (!requestToContinue.empty() && std::tolower(requestToContinue[0]) == 'y');
    
    return 0;
}