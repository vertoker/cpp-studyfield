#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> l;
    std::string temp;

    while (std::cin >> temp)
    {
        l.push_back(temp);
        temp.clear();
    }

    for (const auto& s : l)
        std::cout << s << std::endl;

    return 0;
}