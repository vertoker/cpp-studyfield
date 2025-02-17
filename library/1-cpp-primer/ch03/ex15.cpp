#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> v;

    std::string input;
    while (std::cin >> input)
        v.push_back(input);

    std::cout << v.size() << std::endl;

    return 0;
}