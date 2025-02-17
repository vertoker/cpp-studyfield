#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a; // int
    decltype(a = b) d = a; // int&

    // honestly, I can't understand iin which case I can use this
    // insane syntax decltype(a = b). I understand, that operator=
    // return reference to a, which means type of value is int&,
    // but how I must use it still don't know

    return 0;
}