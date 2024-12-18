#include <iostream>
#include <string>
#include "string.h"

int main()
{
    std::string s1 = "std::string s1";
    std::string s2 = "std::string s2";

    std::cout << "std::string - s1 == s2: " << (s1 == s2) << std::endl;

    const char* c1 = "const char* c1";
    const char* c2 = "const char* c2";

    std::cout << "const char* - strcmp(c1, c2): " << strcmp(c1, c2) << std::endl;

    return 0;
}