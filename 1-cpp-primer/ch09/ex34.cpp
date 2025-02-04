#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data { 1, 2, 3, 4, 5 };

    for (auto cur = data.begin(); cur != data.end(); ++cur)
        if (*cur % 2 == 1)
            cur = data.insert(cur, *cur), ++cur;
    
    for (auto i : data) std::cout << i << " ";
    
    return 0;
}