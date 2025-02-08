#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // ex34
    for (auto rit = vec.crbegin(); rit != vec.crend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // ex35
    for (auto it = std::prev(vec.cend()); true; --it)
    {
        std::cout << *it << " ";
        if (it == vec.cbegin()) break;
    }
    std::cout << std::endl;

    // ex36
    std::list<int> lst = { 1, 2, 3, 4, 0, 5, 6 };
    auto found_0 = std::find(lst.crbegin(), lst.crend(), 0);
    std::cout << std::distance(found_0, lst.crend()) << std::endl;

    // 10.37
    std::list<int> ret_lst(8 - 3);
    std::copy(vec.cbegin() + 3, vec.cbegin() + 8, ret_lst.rbegin());
    //     0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //    ^                  ^
    // rend                  rbegin
    // @note: std::copy copies the range [first, last) into result.
    //        hence, the arguments here denote:
    //        [6 5 4 3 2 1)
    //                   ^ this one is specified but not included.
    // vertoker
    // yes I copy it because I'm tired to write it
    for (auto i : ret_lst)
        std::cout << i << " ";
    std::cout << std::endl;
}