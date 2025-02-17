#include <iostream>

int main()
{
    std::cout << "a" << std::endl;
    std::cout << -30 * 3 + 21 / 5 << std::endl; 
    std::cout << ( ( ( -30 ) * 3 ) + ( 21 / 5 ) ) << std::endl;
    
    std::cout << "b" << std::endl;
    std::cout << -30 + 3 * 21 / 5 << std::endl;
    std::cout << ( ( -30 ) + ( ( 3 * 21 ) / 5 ) ) << std::endl;
    
    std::cout << "c" << std::endl;
    std::cout << 30 / 3 * 21 % 5 << std::endl;
    std::cout << ( ( ( 30 / 3 ) * 21 ) % 5 ) << std::endl;
    
    std::cout << "d" << std::endl;
    std::cout << -30 / 3 * 21 % 4 << std::endl;
    std::cout << ( ( ( ( -30 ) / 3 ) * 21 ) % 4 ) << std::endl;
    return 0;
}