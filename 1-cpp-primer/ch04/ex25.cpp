#include <iostream>
#include <bitset>

int main()
{
    std::bitset<32> a1('q');
    std::bitset<32> a2(~'q');
    std::bitset<32> a3(~'q' << 6);

    std::cout << "\'q\'       - " << a1 << std::endl;
    std::cout << "~\'q\'      - " << a2 << std::endl;
    std::cout << "~\'q\' << 6 - " << a3 << std::endl;
    // 00000000 00000000 00000000 01110001 - 'q'
    // 11111111 11111111 11111111 10001110 - ~'q'
    // 11111111 11111111 11100011 10000000 - ~'q' << 6

    return 0;
}