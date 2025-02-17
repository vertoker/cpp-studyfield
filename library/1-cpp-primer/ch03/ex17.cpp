#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;

    std::string input;
    while (std::cin >> input)
        v.push_back(input);
    
    for (auto& s : v)
        for (auto& c : s)
            c = toupper(c);
    
    for (size_t i = 0; i != v.size(); ++i)
    {
        if (i != 0 && i % 8 == 0) std::cout << std::endl;
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}