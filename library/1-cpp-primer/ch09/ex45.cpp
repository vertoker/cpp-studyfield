#include <iostream>
#include <string>

auto AddPrefixSuffix(std::string name, std::string const& pre, std::string const& su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

int main()
{
    std::string name("Kostya");
    std::cout << AddPrefixSuffix(name, "Mr.", ", Jr.") << std::endl;
    return 0;
}