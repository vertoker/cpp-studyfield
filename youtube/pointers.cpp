#include "stdint.h"
#include <cstdlib>

int main()
{
    int64_t* ptr1 = static_cast<int64_t*>(malloc(sizeof(int64_t)));
    free(ptr1);

    int64_t* ptr2 = new int64_t(123);
    delete ptr2;

    return 0;
}