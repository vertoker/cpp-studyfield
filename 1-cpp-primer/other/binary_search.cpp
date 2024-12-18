#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec {2, 4, 6, 8, 10};
    int searchItem;
    std::cout << "Enter searched item: ";
    std::cin >> searchItem;

    auto begin = ivec.begin(), end = ivec.end();
    auto mid = begin + (end - begin) / 2;

    while (mid != end && *mid != searchItem)
    {
        if (searchItem < *mid)
            end = mid;
        else begin = mid + 1;
        mid = begin + (end - begin) / 2;
    }

    if (mid == end)
        std::cout << "No founded value " << searchItem << std::endl;
    else std::cout << "Value " << *mid << " at index " << mid - ivec.begin() << std::endl;

    return 0;
}