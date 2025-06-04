// Benchmark

#include <chrono>
#include <list>
#include <vector>
#include <iostream>

#include "allocators.cpp" // yes, why not

int main()
{
    const size_t N = 10'000'000;

    while (true)
    {
        auto start = std::chrono::high_resolution_clock::now();

        {
            //std::list<int> list; // 1130 ms
            //std::list<int, Allocator<int>> list; // 1130 ms
            ArenaAllocator<int> alloc(1024 * 1024 * 1024);
            std::list<int, ArenaAllocator<int>> list(alloc); // 380 ms
        
            for (size_t i = 0; i < N; i++)
                list.emplace_back(i);
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Cycle time is " << ms << " ms" << std::endl;
    }
    
}
