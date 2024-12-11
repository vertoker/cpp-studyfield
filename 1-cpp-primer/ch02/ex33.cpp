#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = i;
    auto b = r;
    return 0;
}