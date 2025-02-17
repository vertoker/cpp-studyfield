#include <iostream>
#include <string>

// I'm too lazy to rewrite it
// I already understand how to use it

// case 1: not type using
using std::cin;
using std::cout;

// case 2: type using
using str = std::string;

int main()
{
    str s;
    cin >> s;
    std::cout << s;
    return 0;
}