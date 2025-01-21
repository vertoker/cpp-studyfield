#include <iostream>

void print(const char* s)
{
    if (s)
        while (*s)
            std::cout << *s++;
    std::cout << std::endl;
}

void print(const int* begin, const int* end)
{
    while (begin != end)
        std::cout << *begin++;
    std::cout << std::endl;
}

void print(const int arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        std::cout << arr[i];
    std::cout << std::endl;
}

void print(int (&arr)[2])
{
    for (const auto& i : arr)
        std::cout << i;
    std::cout << std::endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    const char* s = "Hello";

    print(s);
    print(std::begin(j), std::end(j));
    print(j, std::size(j));
    print(j);

    return 0;
}