#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;

    std::string input;
    while (std::cin >> input)
        v.push_back(input);
    
    std::cout << v.size() << std::endl;
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << "hhhh " << i << std::endl;
        std::cout << v.at(0) << " " << std::endl;
    }
    std::cout << std::endl;

    return 0;
}