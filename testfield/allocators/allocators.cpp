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
        //std::cout << "counter:" << *counter << std::endl;
        if (counter != nullptr && --(*counter) == 0)
        {
            //std::cout << "counter2:" << *counter << std::endl;
            operator delete(start);
            operator delete(counter);
        }
    }

public:
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::false_type;
    using propagate_on_container_swap = std::false_type;

    inline size_t getSize() const noexcept { return size; }
    inline char* getStart() const noexcept { return start; }
    inline char* getCurrent() const noexcept { return current; }
    inline int* getCounter() const noexcept { return counter; }

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
        //std::cout << "cp ctor" << std::endl;
        start = other.start;
        current = other.current;
        size = other.size;
        counter = other.counter;
        ++(*counter);
    }
    template <typename U>
    ArenaAllocator(const ArenaAllocator<U>& other)
    {
        //std::cout << "cp U ctor" << std::endl;
        start = other.getStart();
        current = other.getCurrent();
        size = other.getSize();
        counter = other.getCounter();
        ++(*counter);
    }
    ArenaAllocator operator=(const ArenaAllocator& other)
    {
        if (&other == this) return *this;

        deleter();

        start = other.start;
        current = other.current;
        size = other.size;
        
        counter = other.counter;
        ++(*counter);

        return *this;
    }

    ArenaAllocator select_on_container_copy_construction() const // for copy
    {
        std::cout << "select_on_container_copy_construction" << std::endl;
        return ArenaAllocator();
    }

    T* allocate(size_t n)
    {
        size_t bytes = n * sizeof(T);
        auto returnMemory = current;
        current += bytes;

        if (current - start > size)
        {
            std::cout << "Error with bad_alloc: current:" << (current - start) << ", bytes:" << bytes << ", size:" << size << std::endl;
            throw std::bad_alloc();
        }
        //std::cout << "current:" << (current - start) << ", bytes:" << bytes <<  ", size:" << size << std::endl;
        return reinterpret_cast<T*>(returnMemory);
    }
    void deallocate(pointer ptr, size_t n) {}

    void printStatus()
    {
        std::cout << "current:" << (current - start) << ", size:" << size << std::endl;
    }

    template <class U>
    bool operator==(const ArenaAllocator<U>& other) noexcept
    {
        std::cout << "operator==" << std::endl;
        return start == other.start;
    }
    template <class U>
    bool operator!=(const ArenaAllocator<U>& other) noexcept
    {
        return !(*this == other);
    }
};