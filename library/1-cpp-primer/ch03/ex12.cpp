#include <string>
#include <vector>

int main()
{
    std::vector<std::vector<int>> ivec; // yes, it works
    // std::vector<int> svec = ivec; // can't copy, different types
    std::vector<std::string> svec(10, "null"); // special constructor
    return 0;
}