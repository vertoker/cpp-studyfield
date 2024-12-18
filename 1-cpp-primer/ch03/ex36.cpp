#include <iostream>
#include <vector>

bool equals(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size()) return false;

    int* e1 = &v1[v1.size()];
    int *p1 = &v1[0], *p2 = &v2[0];

    while (p1 != e1)
    {
        if (*p1 != *p2)
            return false;
        ++p1; ++p2;
    }
    
    return true;
}

int main()
{
    std::vector<int> vec1 = {2, 4, 6, 8, 10};
    std::vector<int> vec2 = {2, 4, 6, 8, 10};
    
    std::cout << "Vectors is equals: " << equals(vec1, vec2) << std::endl;
    
    return 0;
}