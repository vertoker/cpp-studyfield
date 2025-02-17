#include <iostream>

int main()
{
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int* ptr = ia, ix = 0; ptr != ia + size; ++ix, ++ptr)
    {
        // now can use pointer to indexed number
        // and index itself
    }
    
    return 0;
}