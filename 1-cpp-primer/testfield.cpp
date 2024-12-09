#include <iostream>
#include <string>
#include <vector>

int main()
{
    int var;
    int* addr;

    var = 10;
    std::cout << var << std::endl;

    addr = &var;
    var = *(addr + 1);
    std::cout << var << std::endl;

    addr = &var;
    var = *(addr + 1);
    std::cout << var << std::endl;

    return 0;
}