#include <iostream>
#include <string>
#include "strings/string1.h"

int main()
{
    std::cout << "literal" << std::endl;
    std::string s;

    vertoker::string s1;
    vertoker::string s2("Hello123");
    vertoker::string s3 = std::move(s2);

    std::cout << s1 << std::endl;
    std::cout << s3 << std::endl;
}