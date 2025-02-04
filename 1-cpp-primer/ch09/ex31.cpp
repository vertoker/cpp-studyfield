#include <iostream>
#include <list>
#include <forward_list>

void remove_evens_and_double_odds(std::list<int>& data)
{
    for(auto cur = data.begin(); cur != data.end();)
        if (*cur % 2 == 1)
            cur = data.insert(cur, *cur), advance(cur, 2);
        else
            cur = data.erase(cur);
}

void remove_odds(std::forward_list<int>& data)
{
    auto is_odd = [] (int i) { return i % 2 == 1; };
    data.remove_if(is_odd);
}

int main()
{
    std::list<int> list1 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::forward_list<int> list2 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    remove_evens_and_double_odds(list1);
    remove_odds(list2);

    for (const auto i : list1)
        std::cout << i << " ";
    std::cout << std::endl;

    for (const auto i : list2)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}