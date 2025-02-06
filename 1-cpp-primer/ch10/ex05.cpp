#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string s1 = "Hello";
    std::string s2 = "Hello";
    std::string s3 = "Hella";

    std::cout << std::equal(s1.begin(), s1.end(), s2.begin()) << std::endl;
    std::cout << std::equal(s1.begin(), s1.end(), s3.begin()) << std::endl;

    return 0;
}