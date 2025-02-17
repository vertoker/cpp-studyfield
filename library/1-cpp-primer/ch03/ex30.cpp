#include "stdint.h"

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];

    // array indexing starts with 0
    // must be ix = 0, ix < array_size and ia[ix] = ix + 1
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;
    
    return 0;
}