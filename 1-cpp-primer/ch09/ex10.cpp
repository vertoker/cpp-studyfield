#include <vector>

int main()
{
    std::vector<int> v1;
    const std::vector<int> v2;

    auto it1 = v1.begin(); // iterator
    auto it2 = v2.begin(); // const_iterator by const vector
    auto it3 = v1.cbegin(); // const_iterator by cbegin
    auto it4 = v2.cbegin(); // const_iterator by const vector and cbegin

    return 0;
}