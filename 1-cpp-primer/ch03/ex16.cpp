#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> v {"a", "b", "c"};
    
    std::cout << v.size() << std::endl;
    for (auto i = 0; i < v.size(); ++i)
        std::cout << v[i] << " " << std::endl;
    std::cout << std::endl;
    
    return 0;
}