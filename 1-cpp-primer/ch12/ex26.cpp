#include <iostream>
#include <string>
#include <memory>

void input_reverse_output_string(int n)
{
    std::allocator<std::string> alloc;
    std::string* const p = alloc.allocate(n);
    std::string* q = p;
    std::string s;
    
    while (q != p + n && std::cin >> s)
        alloc.construct(q++, s);
    
    while (q != p)
    {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}

int main()
{
    input_reverse_output_string(5);
}