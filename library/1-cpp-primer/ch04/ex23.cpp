#include <iostream>
#include <string>

int main()
{
    std::string s = "word";
    // condition easy fix with right brackets (string and char not compatible)
    std::string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");

    return 0;
}