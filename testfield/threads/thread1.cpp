#include <iostream>
#include <thread>
#include <vector>

void plus(int* dst, int* src, size_t size)
{
    for (size_t i = 0; i < size; i++)
        dst[i] = dst[i] + src[i];
}

int main()
{
    std::vector<int> dst = { 1, 2, 3, 4, 5 };
    std::vector<int> src = { 5, 4, 3, 2, 1 };

    std::thread t;
    t = std::thread(plus, dst.data(), src.data(), dst.size());
    t.join();

    for (auto& v : dst)
    {
        std::cout << v << std::endl;
    }

    return 0;
}