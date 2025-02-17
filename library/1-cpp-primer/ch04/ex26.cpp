#include <iostream>
#include <bitset>

int main()
{
    unsigned long quiz1 = 0UL;
    unsigned int quiz2 = 0U;

    quiz1 |= 1UL << 27; // 00000000 00000000 00000000 00000000 00001000 00000000 00000000 00000000
    quiz2 |= 1UL << 27; //                                     00001000 00000000 00000000 00000000

    std::bitset<64> q1(quiz1);
    std::bitset<32> q2(quiz2);

    std::cout << "quiz1 = " << q1 << std::endl;
    std::cout << "quiz2 = " << q2 << std::endl;

    return 0;
}