#include <iostream>
#include <vector>
#include <utility>

void Print(const std::vector<int>& vec)
{
    for (const auto i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

// https://education.yandex.ru/journal/osnovnye-vidy-sortirovok-i-primery-ikh-realizatsii

// https://www.w3schools.com/dsa/dsa_data_arrays.php

// Standard

void BubbleSort(std::vector<int>& vec)
{
    for (size_t step = 0; step < vec.size() - 1; ++step)
    {
        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            if (vec[i + 1] < vec[i])
                std::swap(vec[i + 1], vec[i]);
        }
    }
}

void ShakerSort(std::vector<int>& vec)
{
    if (vec.empty()) return;
    size_t left = 0;
    size_t right = vec.size() - 1;

    while (left <= right)
    {
        // from right to left
        for (size_t i = right; i > left; --i)
        {
            if (vec[i] < vec[i - 1]) // if current < next (-)
                std::swap(vec[i - 1], vec[i]);
        }
        ++left;

        // from left to right
        for (size_t i = left; i < right; ++i)
        {
            if (vec[i] > vec[i + 1]) // if current > next (+)
                std::swap(vec[i], vec[i + 1]);
        }
        --right;
    }
}

void CombSort(std::vector<int>& vec)
{
    const double factor = 1 / 1.247;
    
    if (vec.empty()) return;
    double step = static_cast<double>( vec.size() - 1 );

    while (step >= 1)
    {
        size_t stepInt = static_cast<size_t>( step );
        for (size_t i = 0; i + stepInt < vec.size(); i++)
        {
            if (vec[i] > vec[i + stepInt])
                std::swap(vec[i], vec[i + stepInt]);
        }

        step /= factor;
    }
    BubbleSort(vec);
}

// Fast

// TODO why not size_t, without - produce overflow unsigned value error

size_t Partition(std::vector<int>& vec, size_t left, size_t right)
{
    int pivot = vec[right];
    size_t sortedIndex = left - 1;

    for (size_t i = left; i < right; ++i)
    {
        if (vec[i] < pivot)
            std::swap(vec[i], vec[sortedIndex++]);
    }

    std::swap(vec[sortedIndex], vec[right]);
    return sortedIndex;
}
void QuickSortImpl(std::vector<int>& vec, size_t left, size_t right)
{
    //Print(vec);
    if (left < right)
    {
        size_t pivotIndex = Partition(vec, left, right);
        // without it, quick sort can't use size_t as index type
        QuickSortImpl(vec, left, pivotIndex == 0 ? 0 : pivotIndex - 1);
        QuickSortImpl(vec, pivotIndex + 1, right);
    }
}
void QuickSort(std::vector<int>& vec)
{
    if (!vec.empty())
        QuickSortImpl(vec, 0, vec.size() - 1);
}

void MergeSortStepImpl(std::vector<int>& vec, std::vector<int>& buffer, size_t left, size_t mid, size_t right)
{
    size_t k = left;
    for (size_t i = left, j = mid + 1; i <= mid || j <= right; )
    {
        if ( j > right || ( i <= mid && vec[i] < vec[j] ) )
        {
            buffer[k] = vec[i];
            ++i;
        }
        else
        {
            buffer[k] = vec[j];
            ++j;
        }
        ++k;
    }
    for (size_t i = left; i <= right; ++i)
    {
        vec[i] = buffer[i];
    }
}
void MergeSortImpl(std::vector<int>& vec, std::vector<int>& buffer, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = (left + right) / 2;
        MergeSortImpl(vec, buffer, left, mid);
        MergeSortImpl(vec, buffer, mid + 1, right);
        MergeSortStepImpl(vec, buffer, left, mid, right);
    }
}
void MergeSort(std::vector<int>& vec)
{
    if (!vec.empty())
    {
        std::vector<int> buffer(vec.size());
        MergeSortImpl(vec, buffer, 0, vec.size() - 1);
    }
}

void Heapify(std::vector<int>& vec, size_t n, size_t i)
{
    size_t largestIndex = i; // root is largest
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // if left larger than root
    if (left < n && vec[left] > vec[largestIndex])
        largestIndex = left;
    
    // if right larger than root
    if (right < n && vec[right] > vec[largestIndex])
        largestIndex = left;
    
    // if biggest item is not root
    if (largestIndex != i)
    {
        std::swap(vec[i], vec[largestIndex]);
        Heapify(vec, n, largestIndex);
    }
}
void HeapSort(std::vector<int>& vec)
{
    for (size_t i = vec.size() / 2; i > 0; ) // packing
        Heapify(vec, vec.size(), --i);
    
    for (size_t i = vec.size(); i > 0; ) // unpacking
    {
        std::swap(vec[0], vec[--i]);
        Heapify(vec, i, 0);
    }
}

int main()
{
    std::vector<int> vec { 5, 3, 2, 4, 1 };

    //BubbleSort(vec);
    //ShakerSort(vec);
    //CombSort(vec);
    //QuickSort(vec);
    //MergeSort(vec);
    HeapSort(vec);

    Print(vec);
    
    return 0;
}