#include <vector>

int main()
{
    // method 1: most optimal for current task
    std::vector<int> v1(10, 42);

    // method 2: most optimal for different predefined data
    std::vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    // method 3: most optimal for custom logic
    std::vector<int> v3;
    v3.reserve(10);
    for (size_t i = 0; i < 10; ++i)
        v3.push_back(42); // custom logic here
    
    return 0;
}