#include <iostream>
#include <vector>

using VecPtr = std::vector<int>*;

auto make_dynamically()
{
    return new std::vector<int>{};
}

auto populate(VecPtr vecPtr)
{
    for (int i; std::cin >> i; vecPtr->push_back(i));
    return vecPtr;
}

auto print(VecPtr vecPtr) -> std::ostream&
{
    for (auto i : *vecPtr)
        std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_dynamically());
    print(vec) << std::endl;
    delete vec;

    return 0;
}