#include <iostream>

int main()
{
    const char* cp = "Hi";
    if (cp && *cp)
        std::cout << "valid pointer and non zero first char" << std::endl;
    if (cp)
        std::cout << "valid pointer" << std::endl;
    if (*cp)
        std::cout << "non zero first char" << std::endl;
    return 0;
}