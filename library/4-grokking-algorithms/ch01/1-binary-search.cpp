#include <iostream>
#include <type_traits>

int BinarySearch1(int* array, int lowIndex, int highIndex, int toFind)
{
    while (lowIndex <= highIndex)
    {
        // get mid data
        int midIndex = lowIndex + (highIndex - lowIndex) / 2; // lerp with t=0.5
        int midValue = array[midIndex];

        if (toFind == midValue) // if mid is exactly toFind
            return midIndex;
        else if (toFind > midValue) // if toFind located upper
            lowIndex = midIndex + 1; // cut irrelevant half
        else // if (toFind < midValue) // if toFind located lower
            highIndex = midIndex - 1; // cut irrelevant half
    }
    return -1;
}

template<typename T, typename std::enable_if_t<std::is_integral_v<T>, bool> = true>
bool BinarySearch2(const T* array, size_t lowIndex, size_t highIndex, const T& value)
{
    while (lowIndex <= highIndex)
    {
        int midIndex = lowIndex + (highIndex - lowIndex) / 2;
        int midValue = array[midIndex];

        if (value == midValue) return true;
        else if (value > midValue)
            lowIndex = midIndex + 1;
        else // if (value < midValue)
            highIndex = midIndex - 1;
    }
    return false;
}

//template<class ForwardIt>
//bool BinarySearch3()

int main()
{
    const int N = 6;
    int array[N] = { 1, 2, 3, 7, 8, 9 };
    
    std::cout << "v1, value is 8, index is " << BinarySearch1(array, 0, N-1, 8) << std::endl;
    std::cout << "v1, value is 5, index is " << BinarySearch1(array, 0, N-1, 5) << std::endl;

    if (BinarySearch2(array, 0, N-1, 9))
        std::cout << "v2, value is 9, contains" << std::endl;
    else std::cout << "v2, value is 9, not contains" << std::endl;

    if (BinarySearch2(array, 0, N-1, 5))
        std::cout << "v2, value is 5, contains" << std::endl;
    else std::cout << "v2, value is 5, not contains" << std::endl;

    return 0;
}