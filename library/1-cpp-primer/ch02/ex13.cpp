#include <iostream>

int i = 42;
int main()
{
    int i = 100;
    int j = i; // equal 100

    std::cout << i << std::endl;
    std::cout << ::i << std::endl;
}