#pragma once

#include "Deleter.hpp"

#include <cstddef>
#include <utility>

namespace ex28
{
    template <typename, typename>
    class UniquePointer;

    template <typename T, typename D>
    void swap(UniquePointer<T, D>& a, UniquePointer<T, D>& b);

    template <typename T, typename D = Deleter>
    class UniquePointer
    {
        friend void swap<T, D>(UniquePointer<T, D>& a, UniquePointer<T, D>& b);

    public:
        UniquePointer(const UniquePointer&) = delete; // no copy ctor
        UniquePointer& operator=(const UniquePointer&) = delete; // no copy assign

        UniquePointer() = default;
        explicit UniquePointer(T* rawPtr) : ptr(rawPtr) { }

        ~UniquePointer() { deleter(ptr); }

        UniquePointer(UniquePointer&& other) noexcept; // move ctor
        UniquePointer& operator=(UniquePointer&& other) noexcept; // move assign
        UniquePointer& operator=(std::nullptr_t n); // null assign

        T& operator*() const { return *ptr; }
        T* operator->() const { return &this->operator*(); }
        operator bool() const { return ptr ? true : false; }

        T* get() const noexcept { return ptr; }

        inline void swap(UniquePointer<T, D>& other) { ex28::swap(*this, other); }
        void reset() noexcept { deleter(ptr); ptr = nullptr; }
        void reset(T* p) noexcept { deleter(ptr); ptr = p; }

        T* release();

    private:
        T* ptr = nullptr;
        D deleter = D{};
    };

    template <typename T, typename D>
    UniquePointer<T, D>::UniquePointer(UniquePointer&& other) noexcept : ptr{other.ptr}, deleter{other.deleter}
    {
        other.ptr = nullptr;
    }

    template <typename T, typename D>
    UniquePointer<T, D> &UniquePointer<T, D>::operator=(UniquePointer &&rhs) noexcept
    {
        if (this->ptr == rhs.ptr) return *this;

        deleter(ptr);
        ptr = nullptr;
        swap(*this, rhs);
        return *this;
    }

    template<typename T, typename D>
    UniquePointer<T, D>& UniquePointer<T, D>::operator=(std::nullptr_t n)
    {
        if (n == nullptr)
        {
            deleter(ptr);
            ptr = nullptr;
        }
        return *this;
    }
    
    template<typename T, typename D>
    T* UniquePointer<T, D>::release()
    {
        T* ret = ptr;
        ptr = nullptr;
        return ret;
    }

    template <typename T, typename D>
    void swap(UniquePointer<T, D> &a, UniquePointer<T, D> &b)
    {
        std::swap(a.ptr, b.ptr);
        std::swap(a.deleter, b.deleter);
    }

} // namespace ex28
