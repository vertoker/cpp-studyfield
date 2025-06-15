#include <iostream>

int sum(int* start, int n)
{
    if (n == 0) return 0;
    return *start + sum(start + 1, n - 1);
}

int main()
{
    const int N = 4;
    int arr[N] { 1, 2, 3, 4 };
    std::cout << sum(arr, N);

    return 0;
}