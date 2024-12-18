#include <iostream>

int main()
{
    size_t array_size = 10;
    int ia[array_size];

    // the right implementation
    for (size_t ix = 0; ix < array_size; ++ix)
        ia[ix] = ix + 1;
    
    // print it
    for (size_t i = 0; i < array_size; ++i)
        std::cout << ia[i] << ' ';
    
    return 0;
}