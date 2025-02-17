#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<char> src { 'h', 'e', 'l', 'l', 'o' };
    std::string dst(src.cbegin(), src.cend());
    std::cout << dst << std::endl;
    
    return 0;
}