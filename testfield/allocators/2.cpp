// https://habr.com/ru/articles/876804/
// Unuseful

#include <iostream>
#include <vector>

#include <cstdint>
#include <cstring>
#include <cassert>

class StepBackAllocator
{
    char* buffer;
    size_t capacity;
    size_t offset;
    std::vector<void*> history;

public:
    StepBackAllocator(size_t capacity)
        : buffer(new char[capacity]), capacity(capacity), offset(0) { }
    
    StepBackAllocator(size_t capacity, size_t historyReserve)
        : StepBackAllocator(capacity)
    {
        history.reserve(4);
    }
    
    ~StepBackAllocator()
    {
        delete[] buffer;
    }

    void* allocate(const size_t size)
    {
        if (offset + size > capacity) // hasn't enough free memory
            return nullptr; // return not valid allocation
        
        void* newPtr = buffer + offset; // give pointer to the free memory
        history.push_back(newPtr); // remember allocation
        offset += size; // move offset of valid memory
        return newPtr;
    }

    void deallocate(void* ptr)
    {
        if (history.empty())
            assert("No allocations to deallocate");

        if (history.back() == ptr)
            history.pop_back();
    }

    void reset()
    {
        offset = 0;
        history.clear();
    }
};

class SwapAllocator
{
    char* buffer;
    size_t* offsets;
    size_t buffersCount;
    size_t capacity;
    size_t frame; // https://stackoverflow.com/questions/4685610/c-counting-total-frames-in-a-game

public:
    SwapAllocator(size_t buffersCount, size_t capacity)
        : buffer(new char[buffersCount * capacity]), offsets(new size_t[buffersCount]),
            buffersCount(buffersCount), capacity(capacity), frame(0) { reset(); }
    
    ~SwapAllocator()
    {
        delete[] buffer;
        delete[] offsets;
    }

    // default copy constructor? cry about it

    inline void* allocate(size_t size) { return allocate(size, frame % buffersCount); }

    void* allocate(size_t size, size_t index)
    {
        size_t* offset = offsets + index; // pointer to the current index
        if (*offset + size > capacity) // hasn't enough free memory
            return nullptr; // return not valid allocation
        
        void* newPtr = buffer + (index * capacity) + *offset; // give pointer to the free memory
        *offset += size; // move offset of valid memory
        return newPtr;
    }

    void swapBuffers()
    {
        offsets[frame % buffersCount] = 0;
        ++frame;
    }

    void reset()
    {
        // efficiency, enough stable
        memset(offsets, 0, buffersCount * sizeof(size_t));
    }
};

int main()
{
    // StepBack Allocator
    StepBackAllocator allocator1(1024, 8);
    auto p2_1 = static_cast<size_t*>(allocator1.allocate(8));
    auto p2_2 = static_cast<size_t*>(allocator1.allocate(8));
    *p2_1 = 21;
    *p2_2 = 22;
    allocator1.deallocate(p2_2);
    std::cout << *p2_1 << std::endl;
    allocator1.reset();

    // Swap Allocator
    SwapAllocator allocator2(2, 1024);
    auto p3_1 = static_cast<size_t*>(allocator2.allocate(8));
    allocator2.swapBuffers();
    auto p3_2 = static_cast<size_t*>(allocator2.allocate(8));
    allocator2.swapBuffers();
    auto p3_3 = static_cast<size_t*>(allocator2.allocate(8));
    *p3_1 = 31;
    std::cout << *p3_1 << std::endl;
    *p3_2 = 32;
    std::cout << *p3_2 << std::endl;
    *p3_3 = 33;
    std::cout << *p3_3 << std::endl;
    allocator2.reset();

    return 0;
}