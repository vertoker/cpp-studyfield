#include <iostream>
#include <list>

typedef std::list<int>::iterator iter;
typedef std::list<int>::const_iterator citer;

int maxList(iter start, const citer end)
{
    std::cout << *start;
    if (start == end) return -1; // INT_MIN
    return std::max(*start, maxList(++start, end));
}

int main()
{
    std::list<int> l { 1, 2, 3, 4, 1 };
    std::cout << maxList(l.begin(), l.end());

    return 0;
}