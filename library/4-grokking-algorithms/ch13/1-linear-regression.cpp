#include <iostream>

struct vec2
{
    double x;
    double y;

    vec2() : x{0}, y{0} { }
    vec2(double x, double y) : x{x}, y{y} { }
};

// return (a, b) for y=ax+b 
vec2 linearRegression(vec2* dataset, size_t n)
{
    double sumX = 0, sumY = 0, sumYX = 0, sumX2 = 0;

    for (size_t i = 0; i < n; i++)
    {
        vec2 vec = dataset[i];
        sumX += vec.x;
        sumY += vec.y;
        sumYX += vec.y * vec.x;
        sumX2 += vec.x * vec.x;
    }
    
    double invN = 1.0 / n;
    sumX *= invN;
    sumY *= invN;
    sumYX *= invN;
    sumX2 *= invN;

    double a = (sumY * sumX - sumYX) / (sumX * sumX - sumX2);
    double b = (sumYX - a * sumX2) / sumX;
    return vec2(a, b);
}

int main()
{
    vec2 dataset[] {
        vec2(1, 2), vec2(3, 4), vec2(7, 3), vec2(6, 3), vec2(9, 6)
    };
    size_t n = sizeof(dataset) / sizeof(vec2);

    vec2 lr = linearRegression(dataset, n);
    std::cout << "a = " << lr.x << std::endl;
    std::cout << "b = " << lr.y << std::endl;

    return 0;
}