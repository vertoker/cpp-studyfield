#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string s = "Hello";
    
    std::string::iterator beg = s.begin();
    std::string::const_iterator end = s.cend();

    while (beg != s.end())
    {
        // error because of compiler
        // *beg = touppeer(*beg++); // never do this
        *beg = toupper(*beg);
        ++beg;
    }
    
    return 0;
}