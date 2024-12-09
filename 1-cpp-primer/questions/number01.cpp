#include <iostream>
#include <string>
#include <vector>

int main()
{
    unsigned int var;
    unsigned int* addr;

    var = 10;
    std::cout << var << std::endl; // output 10

    addr = &var;
    var = *(addr + 1);
    std::cout << var << std::endl; // output new_var

    addr = &var;
    var = *(addr + 1);
    std::cout << var << std::endl; // output same new_var

    // question 1: why new definition of var doesn't save?

    std::cin.ignore();
    return 0;
}