#include <iostream>
#include <string>
#include <cassert>

int main()
{
    std::string s, sought = "1";
    while (std::cin >> s && s != sought);
    //assert(std::cin); // it's meaningless check
    assert(s == sought && "Incorrect input"); // it's more valuable
    
    return 0;
}