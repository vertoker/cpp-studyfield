#include "allocators.cpp"
#include <vector>

int main()
{
    std::vector<int, ArenaAllocator<int>> vec1 {};
    std::vector<int, ArenaAllocator<int>> vec2 {};
    vec2 = vec1;
    return 0;
}