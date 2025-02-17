#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> lst { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto isOdd = [] (int i) { return i % 2 == 1; };
    lst.remove_if(isOdd);

    for (const auto i : lst)
        std::cout << i << " ";

    return 0;
}