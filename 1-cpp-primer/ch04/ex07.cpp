#include <iostream>

int main()
{
    // numbers overflow or underflow
    
    short num1 = 32767;
    std::cout << "num 1: short overflow" << std::endl;
    std::cout << "src: " << num1 << std::endl;
    num1 += 1;
    std::cout << "dst: " << num1 << std::endl;

    int num2 = -2147483648;
    std::cout << "num 2: int underflow" << std::endl;
    std::cout << "src: " << num2 << std::endl;
    num2 -= 1;
    std::cout << "dst: " << num2 << std::endl;

    unsigned int num3 = 4294967295U;
    std::cout << "num 3: uint overflow" << std::endl;
    std::cout << "src: " << num3 << std::endl;
    num3 += 1;
    std::cout << "dst: " << num3 << std::endl;
    
    return 0;
}