#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned> scores;//(11, 0); // what will go wrong

    unsigned grade;
    while (std::cin >> grade)
        if (grade <= 100)
            ++(*(scores.begin() + grade / 10)); // here, after * will be segfault
    
    return 0;
}