#include <iostream>
#include <list>

typedef std::list<int>::iterator iter;
typedef std::list<int>::const_iterator citer;

int count(iter start, const citer end)
{
    if (start == end) return 0;
    return 1 + count(++start, end);
}

int main()
{
    std::list<int> l { 1, 2, 3, 4, 1 };
    std::cout << count(l.begin(), l.end());

    return 0;
}