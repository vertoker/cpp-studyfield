#include <map>
#include <string>
#include <iostream>

int main()
{
    std::multimap<std::string, std::string> families;

    for (std::string lname, cname; std::cin >> cname >> lname; families.emplace(lname, cname));
    for (const auto& family : families)
        std::cout << family.second << " " << family.first << std::endl;
    
    return 0;
}