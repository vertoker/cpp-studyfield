#include <iostream>

std::istream& ValidateString(std::istream& is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    ValidateString(std::cin);
    return 0;
}