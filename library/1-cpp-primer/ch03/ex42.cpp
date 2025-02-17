#include <vector>

int main()
{
    std::vector<int> int_vec = {0, 1, 2, 3, 4};
    int int_arr[int_vec.size()];

    for (size_t i = 0; i < int_vec.size(); i++)
        int_arr[i] = int_vec[i];
    
    return 0;
}