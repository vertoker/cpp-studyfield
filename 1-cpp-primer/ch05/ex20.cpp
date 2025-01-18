#include <iostream>
#include <string>

int main()
{
    std::string lastWord, input;
    bool successful = false;

    while (std::cin >> input)
    {
        if (lastWord == input)
        {
            successful = true;
            break;
        }
        else
        {
            lastWord = input;
        }
    }

    if (successful)
        std::cout << "Word " << lastWord << " was repeated twice" << std::endl;
    else std::cout << "Sequence doesn't have any repeated words (in a row)" << std::endl;
    
    return 0;
}