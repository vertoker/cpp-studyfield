#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec; // ok
    ivec[0] = 42; // error, ivec.size() equals 0
    return 0;
}