#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool predicate(const std::string& s)
{
    return s.size() >= 5;
}

int main()
{
    std::vector<std::string> v { "a", "aa", "aaaaaaaa", "aaaa", "aaaaaaaaaaaaaaa" };
    auto end = std::partition(v.begin(), v.end(), predicate);

    for (auto it = v.cbegin(); it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}