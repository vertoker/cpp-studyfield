#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> d;
    std::string temp;

    while (std::cin >> temp)
    {
        d.push_back(temp);
        temp.clear();
    }

    for (const auto& s : d)
        std::cout << s << std::endl;

    return 0;
}