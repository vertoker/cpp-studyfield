#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> l { 1, 2, 3, 4, 5 };
    std::deque<int> odd, even;

    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        if (*iter % 2 == 1)
            odd.push_back(*iter);
        else even.push_back(*iter);
    }

    for (const auto i : odd)
        std::cout << i << " ";
    std::cout << std::endl;
    
    for (const auto i : even)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}