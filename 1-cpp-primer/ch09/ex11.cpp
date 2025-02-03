#include <vector>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(v1);
    std::vector<int> v3 = v1;
    std::vector<int> v4 { 1, 2, 3, 4, 5 };
    std::vector<int> v5 = { 1, 2, 3, 4, 5 };
    std::vector<int> v6(10);
    std::vector<int> v7(10, 1);
    std::vector<int> v8(v4.begin(), v4.end());

    return 0;
}