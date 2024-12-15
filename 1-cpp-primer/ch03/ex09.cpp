#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cout << s[0] << std::endl; // here's error

    // s inside self actually is allocate char array with 1 element
    // but it doesn't count, because this symbol is '\0' - control symbol
    // for understanding, where string ends. It doesn't count as symbol

    return 0;
}