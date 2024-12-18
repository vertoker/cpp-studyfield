#include <iostream>

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    
    int* p1 = &arr[0];
    int* p2 = &arr[3];

    // answer: only if pointer address to the out of range [0, n]
    p1 += p2 - p1;
    
    return 0;
}