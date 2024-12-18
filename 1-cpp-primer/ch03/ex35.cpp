#include <iostream>

int main()
{
    const int array_size = 5;
    int arr[array_size] = {2, 4, 6, 8, 10};

    int *e = &arr[array_size];
    for (int* p = arr; p != e; ++p)
        *p = 0;
    
    return 0;
}