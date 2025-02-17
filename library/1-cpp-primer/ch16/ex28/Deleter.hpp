#pragma once

namespace ex28
{
    struct Deleter
    {
        template <typename T>
        void operator()(T* p) const { delete p; }
    };
} // namespace ex28
