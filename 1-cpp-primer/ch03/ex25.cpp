#include <iostream>
#include <vector>

int main()
{
    std::vector<unsigned> scores(11, 0);

    unsigned grade;
    while (std::cin >> grade)
        if (grade <= 100)
            ++(*(scores.begin() + grade / 10));
    
    return 0;
}