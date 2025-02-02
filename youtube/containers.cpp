#include <iostream>

#include <array>
#include <vector>

#include <list>
#include <forward_list>

#include <deque>
#include <queue>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

int main()
{
    // C array

    int a1[10]; // Stack
    int* a2 = new int[10]; // Heap

    a1[7] = 3;
    a1[1] = a1[7];
    // a1[17] = 2; // error, undefined behaviour

    delete a2;


    // static collection, std::array

    std::array<int, 10> a3;
    a3[1] = 2;
    // a3[12] = 4; // error, assert


    // dynamic collection, std::vector

    std::vector<int> v1;
    v1.reserve(1);

    v1.push_back(1);
    v1.push_back(2); // reallocate to size 2


    // Linked list, std::list

    std::list<int> l1;
    
    l1.push_back(3); // 3
    l1.push_back(2); // 3, 2

    l1.remove(3); // 2
    l1.emplace(l1.end(), 1); // 2, 1
    l1.emplace(++l1.begin(), 4); // 2, 4, 1

    std::forward_list<int> l2;

    // front -> 1, 2, ... 8, 9 <- back

    l2.push_front(3); // 3
    l2.push_front(2); // 2, 3

    l2.remove(3); // 2


    // Decks, std::deque

    std::deque<int> d1;

    d1.emplace_back(1); // 1
    d1.emplace_back(2); // 1, 2
    d1.emplace_front(3); // 3, 1, 2

    std::queue<int> d2;

    d2.emplace(1); // 1
    d2.emplace(2); // 1, 2


    // Set, std::set

    std::set<int> h1;

    return 0;
}