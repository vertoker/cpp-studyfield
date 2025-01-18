#include <iostream>
#include <string>

int main()
{
    int maxCount = 0, currentCount = 0;
    std::string maxWord, currentWord, inputWord;

    while (std::cin >> inputWord)
    {
        if (inputWord == currentWord)
        {
            ++currentCount;
        }
        else
        {
            currentCount = 1;
            currentWord = inputWord;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            maxWord = currentWord;
        }
    }

    std::cout << "Max count is " << maxCount << " for word " << maxWord << std::endl;
    return 0;
}