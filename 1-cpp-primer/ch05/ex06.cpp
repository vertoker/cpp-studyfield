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

        // shit
        std::cout << (
              (grade < 60)     ? scores[0] 
            : (grade >= 100)   ? scores[size - 1] 
            : (grade % 10 > 7) ? scores[(grade - 50) / 10] + "+" 
            : (grade % 10 < 3) ? scores[(grade - 50) / 10] + "-" 
            :                    scores[(grade - 50) / 10]
                     ) << std::endl;
    }
    
    return 0;
}