#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    // a
    std::vector<int> vec1;
    std::list<int> list1;

    int i;
    while (std::cin >> i)
        list1.push_back(i);
    
    // use back_inserter because vec1.size() = 0
    std::copy(list1.cbegin(), list1.cend(), std::back_inserter(vec1));

    // b
    std::vector<int> vec2;
    vec2.resize(10); // no use reserve, use resize (or back_inserter)
    std::fill_n(vec2.begin(), 10, 1);

    return 0;
}