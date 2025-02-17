#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Families;

Families MakeFamilies()
{
    Families families;
    for (std::string ln; std::cout << "Parent name:\n", std::cin >> ln && ln != "@q"; )
        for (std::string cn; std::cout << "Children's names:\n", std::cin >> cn && cn != "@q"; )
            families[ln].push_back(cn);
    return families;
}

void print(const Families& families)
{
    for (const auto& family : families)
    {
        std::cout << family.first << ": ";
        for (const auto& child : family.second)
            std::cout << child << " ";
        std::cout << std::endl;
    }
}

int main()
{
    print(MakeFamilies());
    return 0;
}