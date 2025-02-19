#include <iostream>
#include <bitset>
#include <vector>

int main()
{
    std::vector<int> v { 1, 2, 3, 5, 8, 13, 21 };

    std::bitset<32> b1;
    for (auto i : v) b1.set(i);

    std::bitset<32> b2;
    for (unsigned i = 0; i != 32; ++i)
        b2[i] = b1[i];
    
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    
    return 0;
}