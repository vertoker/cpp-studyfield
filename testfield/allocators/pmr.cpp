#include "allocators.cpp"
#include <vector>

#include <memory_resource>

int main()
{
    //std::vector<int, std::pmr::polymorphic_allocator<int>> vec {};
    std::pmr::vector<int> vec {}; // same as above

    return 0;
}