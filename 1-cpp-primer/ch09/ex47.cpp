#include <string>
#include <iostream>

int main()
{
    std::string numbers{ "123456789" };
    std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    std::string str{ "ab2c3d7R4E6" };

    std::cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_of(numbers, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";
    std::cout << "\nalphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_of(alphabet, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";
    std::cout << std::endl;
    
    std::cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";
    std::cout << "\nalphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_not_of(numbers, pos)) != std::string::npos; ++pos)
        std::cout << str[pos] << " ";
    std::cout << std::endl;
    
    return 0;
}