#include <iostream>
#include <string>

int main()
{
    constexpr int size = 6;
    std::string scores[size] = { "F", "D", "C", "B", "A", "A++" };

    int grade;
    while (std::cin >> grade)
    {
        std::string score;
        if (grade < 60)
            score = scores[0];
        else if (grade >= 100)
            score = scores[size - 1];
        else
        {
            score = scores[(grade - 50) / 10];
            if (grade % 10 > 7) score += "+";
            else if (grade % 10 < 3) score += "-";
        }
        std::cout << score << std::endl;
    }
    
    return 0;
}