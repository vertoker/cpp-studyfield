#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("../data/letter.txt");
    if (!ifs) return -1;

    std::string longest;
    auto update_with = [&longest](std::string const& curr)
    {
        if (std::string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    
    for (std::string curr; ifs >> curr; update_with(curr));
    std::cout << longest << std::endl;

    return 0;
}