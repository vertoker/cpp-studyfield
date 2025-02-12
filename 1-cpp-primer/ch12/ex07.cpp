#include <iostream>
#include <vector>
#include <memory>

using Sptr = std::shared_ptr<std::vector<int>>;

auto make_shared()
{
    return std::make_shared<std::vector<int>>();
}

auto populate(Sptr ptr)
{
    for (int i; std::cin >> i; ptr->push_back(i));
    return ptr;
}

auto print(Sptr ptr) -> std::ostream&
{
    for (auto i : *ptr)
        std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_shared());
    print(vec) << std::endl;

    return 0;
}