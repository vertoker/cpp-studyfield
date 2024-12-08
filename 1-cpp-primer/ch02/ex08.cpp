#include <iostream>

// https://www.asciitable.com
// idk, but it uses oct codes, not dec
int main()
{
    std::cout << "\062\115\012";
    std::cout << "\062\011\115\012";
    std::cout << "2M\n";
    std::cout << "2\tM\n";
    return 0;
}