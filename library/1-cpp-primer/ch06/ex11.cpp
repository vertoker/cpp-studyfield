#include <iostream>

void reset(int& i)
{
    i = 0;
}

int main()
{
    int i = -1;
    std::cout << "i = " << i << std::endl;
    reset(i);
    std::cout << "i = " << i << std::endl;
    return 0;
}