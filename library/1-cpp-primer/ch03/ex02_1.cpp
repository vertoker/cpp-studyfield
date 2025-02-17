#include <string>
#include <iostream>

int main()
{
    std::string s;
    while (std::getline(std::cin, s))
        std::cout << s << std::endl;
    
    return 0;
}