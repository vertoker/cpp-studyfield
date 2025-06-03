#include <iostream>

// Literally copy of std::allocator (stateless)

template <class T>
class Allocator
{
public:
    // Core functionality

    using value_type = T;

    T* allocate(size_t n)
    {
        //std::cout << "Items: " << n << " allocate: " << n * sizeof(T) << " bytes\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    void deallocate(T* ptr, size_t n)
    {
        //std::cout << "Deallocate: " << n * sizeof(T) << " bytes\n";
        ::operator delete(ptr);
    }
};

// Assignment

template <class T, class U>
bool operator==(Allocator<T> const& a, Allocator<U> const& b) noexcept
{
    // Perfect for no contained anything allocators
    return true;
}

// First statefull allocator - ArenaAllocator (Linear, Region)
// Arena allocator? Oh yes, the place where allocators fight for memory

template <typename T>
class ArenaAllocator
{
private:
    size_t size;
    char*  start;
    char*  current;

    int* counter;

    void deleter()
    {
        std::cout << "counter:" << *counter << std::endl;
        (*counter)--;
        if (*counter == 0)
        {
            std::cout << "counter2:" << *counter << std::endl;
            operator delete(start);
            operator delete(counter);
        }
    }

public:
    using value_type = T;

    ArenaAllocator(size_t bytes = 1024 * 1024) : size(bytes), 
        start(static_cast<char*>(operator new(bytes))),
        current(start), counter(new int(1))
    { }
    ~ArenaAllocator()
    {
        deleter();
    }

    ArenaAllocator(const ArenaAllocator& other)
    {
        std::cout << "cp ctor" << std::endl;
        this->start = other.start;
        this->current = other.current;
        this->size = other.size;
        this->counter = other.counter;
        ++(*this->counter);
    }
    ArenaAllocator(ArenaAllocator&& other)
    {
        std::cout << "mv ctor" << std::endl;
        this->start = other.start;
        this->current = other.current;
        this->size = other.size;
        this->counter = other.counter;
        other.start = nullptr;
        other.current = nullptr;
        other.size = 0;
        other.counter = nullptr;
    }

    T* allocate(size_t n)
    {
        // TODO разобраться с этим завтра
        size_t bytes = n * sizeof(T);
        auto returnMemory = current;
        current += bytes;

        if (current - start > size)
        {
            std::cout << "Error with bad_alloc: current:" << (current - start) << ", size:" << size << std::endl;
            throw std::bad_alloc();
        }
        std::cout << "current:" << (current - start) << ", bytes:" << bytes <<  ", size:" << size << std::endl;
        return reinterpret_cast<T*>(returnMemory);
    }
    void deallocate(T* ptr, size_t n) {}

    void printStatus()
    {
        std::cout << "current:" << (current - start) << ", size:" << size << std::endl;
    }
};