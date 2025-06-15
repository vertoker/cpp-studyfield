#include <iostream>

void qsort(int* arr, int size)
{
    if (size <= 1) return;

    --size;
    int pivot = arr[size];
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= pivot)
            std::swap(arr[i], arr[counter++]);
    }
    
    std::swap(arr[counter], arr[size]);

    qsort(arr, counter);
    qsort(arr + counter + 1, size - counter);
}

int main()
{
    const int N = 9;
    int arr[N] { 3, 7, 8, 5, 2, 1, 9, 5, 4 };

    qsort(arr, N);

    for (auto& i : arr)
        std::cout << i << ' ';
    
    return 0;
}