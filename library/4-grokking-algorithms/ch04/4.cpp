
int BinarySearch1(int* array, int startIndex, int endIndex, int toFind)
{
    while (startIndex <= endIndex)
    {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        int midValue = array[midIndex];

        if (toFind == midValue) // base case
            return midIndex;
        else if (toFind > midValue) // recursive case
            startIndex = midIndex + 1;
        else // if (toFind < midValue) // recursive case
            endIndex = midIndex - 1;
    }
    return -1;
}