#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

std::vector<std::string>::iterator biggies(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);
    
    return std::partition(vs.begin(), vs.end(), 
        [sz](std::string const& s){ return s.size() >= sz; });
}

int main()
{
    std::vector<std::string> v { "123", "123", "123", "kostya", "churakov" };
    auto end = biggies(v, 3);
    
    for (auto begin = v.begin(); begin != v.end(); ++begin)
        std::cout << *begin << " ";
    std::cout << std::endl;

    return 0;
}