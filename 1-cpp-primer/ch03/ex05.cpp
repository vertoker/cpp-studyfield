#include <iostream>
#include <string>

int main()
{
    std::string temp, all;
    while (std::cin >> temp)
        all += temp;
    std::cout << all << std::endl;
    
    return 0;
}