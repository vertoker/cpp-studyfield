#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::cout << "Enter text: ";
    std::cin >> input;

    int vowelCount = 0, consonantCount = 0, spaceCount = 0, tabCount = 0, newlineCount = 0, pair2Count = 0, otherCount = 0;
    for (auto i = 0; i < input.size(); ++i)
    {
        auto ch = std::tolower(input[i]);

        switch (ch)
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            ++vowelCount;
            break;
        case 'b': case 'c': case 'd': case 'g': case 'h':
        case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'p': case 'q': case 'r': case 's': case 't':
        case 'v': case 'w': case 'x': case 'y': case 'z':
            ++consonantCount;
            break;
        case 'f':
            ++consonantCount;
            if (i + 1 < input.size())
            {
                auto ch2 = std::tolower(input[i + 1]);
                if (ch2 == 'f' || ch2 == 'l' || ch2 == 'i')
                    ++pair2Count;
            }
            break;
        case ' ':
            ++spaceCount;
            break;
        case '\t':
            ++tabCount;
            break;
        case '\n':
            ++newlineCount;
            break;
        default:
            ++otherCount;
            break;
        }
    }

    std::cout << "Vowel count: " << vowelCount << std::endl;
    std::cout << "Consonant count: " << consonantCount << std::endl;
    std::cout << "Space count (ex11): " << spaceCount << std::endl;
    std::cout << "Tab count (ex11): " << tabCount << std::endl;
    std::cout << "Newline count (ex11): " << newlineCount << std::endl;
    std::cout << "Pair2 count (ex12): " << pair2Count << std::endl;
    std::cout << "Other count: " << otherCount << std::endl;

    return 0;
}