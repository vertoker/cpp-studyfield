#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };
    
    auto begin = v.begin();
    while (begin != v.end())
    {
        ++begin;
        /*begin = */v.insert(begin, 42);
        ++begin;
    }
    // infinite loop, begin never be equal end

    for (auto i : v) std::cout << i << " ";

    return 0;
}