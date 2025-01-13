#include <iostream>
#include <string>

bool find(const std::string& word)
{
    return true;
}

int main()
{
    // a
    std::string word = "Hello";
    std::string::iterator iter = word.begin();
    while (iter != word.end())
        std::cout << *iter, ++iter;
    std::cout << std::endl;
    
    // b
    while (bool status = find(word))
    {
        if (!status)
            std::cout << "no status?";
        std::cout << "yes status" << std::endl;
        break;
    }
    
    return 0;
}