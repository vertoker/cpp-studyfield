#include <vector>
#include <list>
#include <string>
#include <iostream>

int main()
{
    std::cout << sizeof(std::vector<int>::size_type) << std::endl;
    
    std::list<std::string>::const_iterator toRead;
    std::list<std::string>::iterator toWrite;

    return 0;
}