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
    while (iter != word.end()) // iter already declared higher, here's just assignment
        std::cout << *iter, ++iter;
    std::cout << std::endl;
    
    // b
    while (bool status = find(word))
    {
        if (!status) // I can't define that if outside of that while
            std::cout << "no status?";
        std::cout << "yes status" << std::endl;
        break;
    }
    
    return 0;
}