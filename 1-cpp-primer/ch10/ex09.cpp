#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void println(std::vector<std::string>& v)
{
    for (const auto& o : v)
        std::cout << o << " ";
    std::cout << std::endl;
}

void eliminate_dublicates(std::vector<std::string>& vs)
{
    std::sort(vs.begin(), vs.end());
    auto uniqueIterator = std::unique(vs.begin(), vs.end());
    vs.erase(uniqueIterator, vs.end());
}

int main()
{
    std::vector<std::string> v { "m", "i", "s", "s", "i", "s", "s", "i", "p", "p", "i" };
    println(v);
    eliminate_dublicates(v);
    println(v);

    return 0;
}