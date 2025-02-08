#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

template <typename Container>
void print(Container& container)
{
    for (const auto& o : container)
        std::cout << o << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::list<int> lst;

    // inserter
    lst.clear();
    std::copy(vec.begin(), vec.end(), std::inserter(lst, lst.begin()));
    print(lst);

    // back_inserter
    lst.clear();
    std::copy(vec.begin(), vec.end(), std::back_inserter(lst));
    print(lst);

    // front_inserter
    lst.clear();
    std::copy(vec.begin(), vec.end(), std::front_inserter(lst));
    print(lst);

    return 0;
}