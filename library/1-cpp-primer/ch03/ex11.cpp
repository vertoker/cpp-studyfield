#include <iostream>
#include <string>

int main()
{
    const std::string s = "Wait it's a const?";
    for (auto& c : s) // c is a const char&, because s is a const string
        // c = 'x'; // illegal, because of const
        std::cout << c << std::endl;
    
    return 0;
}