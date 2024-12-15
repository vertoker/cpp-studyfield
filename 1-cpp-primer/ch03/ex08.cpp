#include <iostream>
#include <string>

// copy of ex06.cpp
int main()
{
    std::string line = "Hello world!";
    std::cout << line << std::endl;
    
    // for as 'foreach'
    for (auto& c : line)
        c = 'x';
    std::cout << line << std::endl;

    // for as default
    for (size_t i = 0; i < line.size(); i++)
        line[i] = 'y';
    std::cout << line << std::endl;
    
    // while
    size_t counter = 0;
    while (counter < line.size())
    {
        line[counter] = 'z';
        ++counter;
    }
    std::cout << line << std::endl;
    
    return 0;
}