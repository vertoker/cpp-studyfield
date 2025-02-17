#include <iostream>

int main()
{
    int i = 10;
    int *pi = &i;
    std::cout << *pi << std::endl;

    int i2 = 20;
    pi = &i2;
    std::cout << *pi << std::endl;

    *pi = 30;
    std::cout << *pi << std::endl;

    i2 = 40;
    std::cout << *pi << std::endl;
    
    return 0;
}