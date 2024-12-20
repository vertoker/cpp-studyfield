#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << ((a > b > c > d) ? "true" : "false") << std::endl;
    
    return 0;
}