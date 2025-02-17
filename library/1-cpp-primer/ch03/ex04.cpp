#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;

    std::cout << "Enter s1: ";
    std::getline(std::cin, s1);
    std::cout << "Enter s2: ";
    std::getline(std::cin, s2);

    if (s1 == s2)
    {
        std::cout << "s1 and s2 are equals, size = " << s1.size() << std::endl;
    }
    else if (s1.size() == s2.size())
    {
        std::cout << "s1 and s2 sizes are equals, size = " << s1.size() << std::endl;
    }
    else if (s1.size() > s2.size())
    {
        std::cout << "s1 is bigger than s2, s1 size = " << s1.size() << ", s2 size = " << s2.size() << std::endl;
    }
    else if (s2.size() > s1.size())
    {
        std::cout << "s2 is bigger than s1, s1 size = " << s1.size() << ", s2 size = " << s2.size() << std::endl;
    }
    return 0;
}