#include <iostream>
#include <string>

int main()
{
    std::string line("Hello world!");

    std::cout << line << std::endl;
    for (auto& c : line)
        c = 'X';
    std::cout << line << std::endl;
    
    return 0;
}