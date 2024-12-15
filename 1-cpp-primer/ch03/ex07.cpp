#include <iostream>
#include <string>

// copy of ex06.cpp
int main()
{
    std::string line("Hello world!");

    std::cout << line << std::endl;
    for (char c : line) // replace auto& to char
        c = 'X'; // it just change local variable, therefore do not change `line`
    std::cout << line << std::endl; // answer is the same
    
    return 0;
}