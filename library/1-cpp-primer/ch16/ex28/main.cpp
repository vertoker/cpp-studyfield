#include "SharedPointer.hpp"
#include "UniquePointer.hpp"

int main()
{
    ex28::SharedPointer<int> sptr1(new int(234));
    ex28::SharedPointer<int> sptr2(sptr1);
    ex28::SharedPointer<int> sptr3;

    ex28::UniquePointer<int> uptr1(new int(345));
    ex28::UniquePointer<int> uptr2(std::move(uptr1));
    
    return 0;
}