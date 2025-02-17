#include <iostream>

int main()
{
    // const int buf; // no initializer
    int cnt = 0; // regular variable
    const int sz = cnt; // contains intializer
    ++cnt; // regular variable 
    // ++sz; // write protected
    return 0;
}