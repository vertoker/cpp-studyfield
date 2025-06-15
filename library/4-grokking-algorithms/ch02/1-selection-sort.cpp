#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr)
{
    int n = arr.size();

    for (size_t i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> v { 4, 5, 1, 3, 2 };

    selectionSort(v);

    for (const auto& i : v)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}