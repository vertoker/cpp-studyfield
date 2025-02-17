#include <iostream>

int main()
{
    int i = 42;
    void *pi1 = &i; // why this works
    // long *pi2 = &i; // and this don't

    // because pointers can do upcast to their parent types, implicitly
    // but can't do the same thing with downcast, only explicitly
    
    long long *pi2 = (long long*)pi1;
    // as you can see, I can do explicit conversion
    // but in that case, this is shit code, because long long > int and 
    // that cast is unsafe as hell, don't do this

    // std::cout << *pi1 << std::endl; // also you can't print pointer without type
    std::cout << *pi2 << std::endl;

    return 0;
}