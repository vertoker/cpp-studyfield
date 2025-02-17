#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string input, output;
    std::cin >> input;

    output.reserve(input.size());
    for (auto& c : input)
        if (!ispunct(c))
            output.push_back(c);
    std::cout << output << std::endl;

    return 0;
}