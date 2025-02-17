#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
    std::list<const char*> l { "1", "2", "3" };
    std::vector<std::string> v;
    v.assign(l.begin(), l.end());

    for (const auto& o : v)
        std::cout << o << std::endl;

    return 0;
}