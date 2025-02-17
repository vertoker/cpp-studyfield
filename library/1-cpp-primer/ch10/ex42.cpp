#include <iostream>
#include <string>
#include <list>

void elimDups(std::list<std::string>& words)
{
    words.sort();
    words.unique();
}

int main()
{
    std::list<std::string> l = { "aa", "aa", "aa", "aa", "aasss", "aa" };
    elimDups(l);
    
    for (const auto& e : l)
        std::cout << e << " ";
    std::cout << std::endl;
}