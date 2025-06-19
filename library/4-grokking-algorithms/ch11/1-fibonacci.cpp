#include <iostream>
#include <chrono>

// https://brestprog.by/topics/dp/

size_t fibRec(size_t n)
{
    if (n <= 2) return 1;
    return fibRec(n - 1) + fibRec(n - 2);
}

size_t fibDP(size_t n)
{
    size_t fib[n + 1]; // fib[0] is unused
    fib[1] = fib[2] = 1; // initial values

    for (size_t i = 3; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2]; // transition formula
    
    return fib[n]; // answer computation
}

int main()
{
    size_t n;
    std::cout << "How many fib count (exponential starts with 43): ";
    std::cin >> n;

    auto start1 = std::chrono::high_resolution_clock::now();
    size_t fib1 = fibRec(n);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    size_t fib2 = fibDP(n);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto time1 = std::chrono::duration<double, std::milli>(end1 - start1).count();
    auto time2 = std::chrono::duration<double, std::milli>(end2 - start2).count();
    
    std::cout << "fibRec(n) = " << fib1 << ", time = " << time1 << " ms\n"; // 50 - 38272.1 ms
    std::cout << "fibDP(n) = " << fib2 << ", time = " << time2 << " ms";    // 50 - 0.0002 ms

    return 0;
}