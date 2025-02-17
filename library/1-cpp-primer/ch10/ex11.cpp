#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

inline bool lessSize(std::string const& l, std::string const& r)
{
    return l.size() < r.size();
}

void elimdups(std::vector<std::string>& vs) // eliminate_dublicates
{
    std::sort(vs.begin(), vs.end());
    auto uniqueIterator = std::unique(vs.begin(), vs.end());
    vs.erase(uniqueIterator, vs.end());
}

int main()
{
    std::vector<std::string> v { "1234", "1234", "1234", "I'm", "Kostya", "Churakov" };
    elimdups(v);
    std::stable_sort(v.begin(), v.end(), lessSize);
    
    for (const auto& s : v)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}