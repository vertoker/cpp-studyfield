#include <vector>

int main()
{
    int int_arr[] = {0, 1, 2, 3, 4};
    std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    return 0;
}