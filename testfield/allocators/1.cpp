// https://habr.com/ru/articles/876804/
// Useful

#include <iostream>
#include <vector>

#include <cstdint>
#include <cassert>
#include <cstring>

// usually for any temp data, frame data for 1-2 frames

class LinearAllocator
{
    char* buffer;
    const size_t capacity;
    size_t offset;

public:
    LinearAllocator(size_t capacity) : capacity(capacity), offset(0)
    {
        buffer = static_cast<char*>(malloc(capacity));
    }

    ~LinearAllocator()
    {
        free(buffer);
    }

    // default copy constructor? cry about it

    void* allocate(size_t size)
    {
        if (offset + size > capacity) // hasn't enough free time
            return nullptr; // return not valid allocation
        
        void* newPtr = buffer + offset; // give pointer to the free memory
        offset += size; // move offset of valid memory
        return newPtr;
    }

    void reset()
    {
        offset = 0; // memory can be uncleared, this is different operation
    }
};

// usually use for parsers text parsers and procedural generation
// also any recursive algorithms
// works with LIFO (Last In First Out), like classic stack

class StackAllocator
{
    char* buffer;
    const size_t capacity;
    char* current;

    struct Header {
        size_t size;
    };

    // Header needed for check correction of deallocation
    // Also that struct add some extentibility for other allocator types

public:
    StackAllocator(size_t capacity) : capacity(capacity)
    {
        buffer = static_cast<char*>(malloc(capacity));
        current = buffer;
    }

    ~StackAllocator()
    {
        free(buffer);
    }

    // default copy constructor? cry about it

    void* allocate(size_t size)
    {
        if (current + sizeof(Header) + size > buffer + capacity)
            return nullptr;
        
        auto header = (Header*)current;
        header->size = size;
        current += sizeof(Header);
        void* ptr = current;
        current += size;
        return ptr;
    }

    void deallocate(void* ptr)
    {
        if (!ptr) return;

        char* charPtr = static_cast<char*>(ptr);
        Header* header = (Header*)(charPtr - sizeof(Header));
        if (charPtr + header->size != current)
            assert("incorrent free");
        current = (char*)header;
    }

    void reset()
    {
        current = buffer;
    }
};

// specific pattern for double loading of something
// in start - something heavy, in end - something small

class DoubleLinearAllocator
{
    char* buffer;
    const size_t capacity;
    size_t offsetStart;
    size_t offsetEnd;

public:
    DoubleLinearAllocator(size_t capacity) : capacity(capacity), offsetStart(0), offsetEnd(capacity)
    {
        buffer = static_cast<char*>(malloc(capacity));
    }

    ~DoubleLinearAllocator()
    {
        free(buffer);
    }

    // default copy constructor? cry about it

    void* allocateStart(size_t size)
    {
        if (offsetStart + size > offsetEnd) // hasn't enough free time
            return nullptr; // return not valid allocation
        
        void* newPtr = buffer + offsetStart; // give pointer to the free memory
        offsetStart += size; // move offset of valid memory
        return newPtr;
    }
    void* allocateEnd(size_t size)
    {
        if (offsetEnd - size < offsetStart) // hasn't enough free time
            return nullptr; // return not valid allocation
        
        offsetEnd -= size; // move offset of valid memory
        void* newPtr = buffer + offsetEnd; // give pointer to the free memory
        return newPtr;
    }

    void reset()
    {
        offsetStart = 0;
        offsetEnd = capacity;
    }
};

// specific pattern for double loading of something
// in start - something heavy, in end - something small

class DoubleStackAllocator
{
    char* buffer;
    const size_t capacity;
    char* currentStart;
    char* currentEnd;

    struct Header {
        size_t size;
    };

    // Header needed for check correction of deallocation
    // Also that struct add some extentibility for other allocator types

    // header -> data

public:
    DoubleStackAllocator(size_t capacity) : capacity(capacity)
    {
        buffer = static_cast<char*>(malloc(capacity));
        reset();
    }

    ~DoubleStackAllocator()
    {
        free(buffer);
    }

    // default copy constructor? cry about it

    void* allocateStart(size_t size)
    {
        if (currentStart + sizeof(Header) + size > currentEnd)
            return nullptr;
        
        auto header = (Header*)currentStart;
        header->size = size;
        currentStart += sizeof(Header);

        void* ptr = currentStart;
        currentStart += size;

        return ptr;
    }
    void* allocateEnd(size_t size)
    {
        if (currentEnd - size - sizeof(Header) < currentStart)
            return nullptr;
        
        currentEnd -= size;
        void* ptr = currentEnd;

        currentEnd -= sizeof(Header);
        auto header = (Header*)currentEnd;
        header->size = size;

        return ptr;
    }

    void deallocateStart(void* ptr)
    {
        if (!ptr) return;

        char* charPtr = static_cast<char*>(ptr);
        Header* header = (Header*)(charPtr - sizeof(Header));

        if (charPtr + header->size != currentStart)
            assert("incorrent free memory in start stack");
        currentStart = (char*)header;
    }
    void deallocateEnd(void* ptr)
    {
        if (!ptr) return;

        char* charPtr = static_cast<char*>(ptr);
        Header* header = (Header*)(charPtr - sizeof(Header));
        charPtr += header->size;

        if (charPtr != currentEnd)
            assert("incorrent free memory in end stack");
        currentEnd = (char*)charPtr;
    }
    void deallocate(void* ptr)
    {
        if (!ptr) return;

        char* charPtr = static_cast<char*>(ptr);
        Header* header = (Header*)(charPtr - sizeof(Header));

        if (charPtr + header->size == currentStart)
            currentStart = (char*)header;
        else if (charPtr + header->size == currentStart)
            currentEnd = charPtr + header->size;
        else assert("incorrent free memory in double stack");
    }

    void reset()
    {
        currentStart = buffer;
        currentEnd = buffer + capacity;
    }
};

class PoolAllocator
{
    struct Block
    {
        Block* next;
    };

    char* buffer;
    Block* freeBlocks;
    size_t blockSize;
    size_t blocksCount;

public:
    PoolAllocator(size_t size, size_t count)
    {
        blockSize = (size < sizeof(Block)) ? sizeof(Block) : size;
        blocksCount = count;

        buffer = new char[blockSize * blocksCount];
        reset();
    }
    ~PoolAllocator()
    {
        delete[] buffer;
    }

    void* allocate()
    {
        if (!freeBlocks) return nullptr;
        Block* ptr = freeBlocks;
        freeBlocks = freeBlocks->next;
        return ptr;
    }
    void deallocate(void* ptr)
    {
        if (!ptr) return;
        Block* block = static_cast<Block*>(ptr);
        block->next = freeBlocks;
        freeBlocks = block;
    }

    void reset()
    {
        freeBlocks = reinterpret_cast<Block*>(buffer);
        Block* current = freeBlocks;
        for (size_t i = 1; i < blocksCount; ++i)
        {
            current->next = reinterpret_cast<Block*>(reinterpret_cast<char*>(current) + blockSize);
            current = current->next;
        }
        current->next = nullptr;
    }
};

template <typename T>
class PoolAllocatorT
{
    struct Block
    {
        Block* next;
    };

    char* buffer;
    Block* freeBlocks;
    size_t blocksCount;

    static_assert(sizeof(Block) <= sizeof(T) && "Type can't be less than pool block (min 8 bytes)");

public:
    PoolAllocatorT(size_t count)
    {
        blocksCount = count;
        buffer = new char[sizeof(T) * blocksCount];
        reset();
    }
    ~PoolAllocatorT()
    {
        delete[] buffer;
    }

    T* allocate()
    {
        if (!freeBlocks) return nullptr;
        T* ptr = reinterpret_cast<T*>(freeBlocks);
        freeBlocks = freeBlocks->next;
        memset(ptr, 0, sizeof(T));
        return ptr;
    }
    void deallocate(void* ptr)
    {
        if (!ptr) return;
        Block* block = static_cast<Block*>(ptr);
        block->next = freeBlocks;
        freeBlocks = block;
    }

    void reset()
    {
        freeBlocks = reinterpret_cast<Block*>(buffer);
        Block* current = freeBlocks;
        for (size_t i = 1; i < blocksCount; ++i)
        {
            current->next = reinterpret_cast<Block*>(reinterpret_cast<char*>(current) + sizeof(T));
            current = current->next;
        }
        current->next = nullptr;
    }
};

class ArenaAllocator
{
    struct Arena
    {
        char* buffer;
        size_t size;
        size_t used;
        uint32_t actives;

        Arena(size_t size) : buffer(new char[size]), size(size), used(0), actives(0) { }
        ~Arena() { delete[] buffer; }
    };
};

int main()
{
    // Linear Allocator
    LinearAllocator allocator1(1024);
    auto p1_1 = static_cast<size_t*>(allocator1.allocate(8));
    *p1_1 = 11;
    std::cout << *p1_1 << std::endl;
    allocator1.reset();

    // Stack Allocator
    StackAllocator allocator2(1024);
    auto p2_1 = static_cast<size_t*>(allocator2.allocate(8));
    auto p2_2 = static_cast<size_t*>(allocator2.allocate(8));
    *p2_1 = 21; *p2_2 = 22;
    std::cout << *p2_1 << std::endl << *p2_2 << std::endl;
    allocator2.deallocate(p2_2);
    allocator2.deallocate(p2_1);
    allocator2.reset();

    // Double Linear Allocator
    DoubleLinearAllocator allocator3(1024);
    auto p3_1 = static_cast<size_t*>(allocator3.allocateStart(8));
    auto p3_2 = static_cast<size_t*>(allocator3.allocateEnd(8));
    *p3_1 = 31; *p3_2 = 32;
    std::cout << *p3_1 << std::endl << *p3_2 << std::endl;
    allocator3.reset();

    // Double Stack Allocator
    DoubleStackAllocator allocator4(1024);
    auto p4_1 = static_cast<size_t*>(allocator4.allocateStart(8));
    auto p4_2 = static_cast<size_t*>(allocator4.allocateEnd(8));
    auto p4_3 = static_cast<size_t*>(allocator4.allocateStart(8));
    *p4_1 = 41; *p4_2 = 42; *p4_3 = 43;
    std::cout << *p4_1 << std::endl << *p4_2 << std::endl << *p4_3 << std::endl;
    allocator4.deallocate(p4_3);
    allocator4.deallocateEnd(p4_2);
    allocator4.deallocateStart(p4_1);
    allocator3.reset();

    // Pool Allocator
    PoolAllocator allocator5(8, 128);
    auto p5_1 = static_cast<size_t*>(allocator5.allocate());
    auto p5_2 = static_cast<size_t*>(allocator5.allocate());
    *p5_1 = 51; *p5_2 = 52;
    std::cout << *p5_1 << std::endl << *p5_2 << std::endl;
    allocator5.deallocate(p5_2);
    allocator3.reset();

    // Template Pool Allocator
    PoolAllocatorT<size_t> allocator6(128);
    auto p6_1 = allocator6.allocate();
    auto p6_2 = allocator6.allocate();
    *p6_1 = 61; *p6_2 = 62;
    std::cout << *p6_1 << std::endl << *p6_2 << std::endl;
    allocator6.deallocate(p6_2);
    allocator6.deallocate(p6_1);
    allocator3.reset();

    return 0;
}