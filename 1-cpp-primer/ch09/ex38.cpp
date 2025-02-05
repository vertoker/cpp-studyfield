#include <iostream>
#include <vector>

void add(std::vector<int>& v, int value)
{
    v.push_back(value);
    std::cout << "push_back - " << value << std::endl;
}

void status(const std::vector<int>& v)
{
    std::cout << "size=" << v.size() << ", capacity=" << v.capacity() << std::endl;
}

int main()
{
    std::vector<int> v;
    status(v);

    for (size_t i = 1; i <= 10; ++i)
    {
        add(v, i);
        status(v);
    } // grow factor = 2
    
    return 0;
}