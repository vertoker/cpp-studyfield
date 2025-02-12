#include <iostream>
#include <memory>

int main()
{
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    delete p;
    // runtime error, sp try to delete already deleted pointer

    return 0;
}