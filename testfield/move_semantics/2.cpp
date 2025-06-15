#include <iostream>
#include <vector>

int main()
{
    int x = 1;
    
    const int& crx = 5;
    int& rx = x;

    int&& r = 5;
    int& a = r;
    
    return 0;
}