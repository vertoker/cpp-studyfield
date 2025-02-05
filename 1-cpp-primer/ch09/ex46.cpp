#include <iostream>
#include <string>

auto AddPrefixSuffix(std::string name, std::string const& prefix, std::string const& suffix)
{
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    name.insert(name.size(), suffix);
    return name;
}

int main()
{
    std::string name("Kostya");
    std::cout << AddPrefixSuffix(name, "Mr.", ", Jr.") << std::endl;
    return 0;
}