// Benchmark

#include <chrono>
#include <list>
#include <vector>
#include <iostream>

#include "allocators.cpp" // yes, why not

int main()
{
    const size_t N = 10'000'000;

    //while (true)
    {
        auto start = std::chrono::high_resolution_clock::now();

        {
            //std::vector<int> vec; // 1100 ms
            //std::vector<int, Allocator<int>> vec; // 1100 ms
            ArenaAllocator<int> alloc(1024 * 1024 * 400);
            std::vector<int, ArenaAllocator<int>> vec {alloc}; // 250-280 ms
        
            for (size_t i = 0; i < N; i++)
                vec.emplace_back(i);
            
            alloc.printStatus();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto ms = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Cycle time is " << ms << " ms" << std::endl;
    }
    
}
