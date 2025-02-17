#include <iostream>
#include <vector>
#include <string>
#include <memory>

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;

    //IntP p0(ix); // error, ix is not a pointer

    // IntP p1(pi); // runtime error, on delete it try to delete stack variable ix, which is not possible (because it's not a heap)

    { IntP p2(pi2); } // runtime error, in scope everything is fine, but after - pi2 will be deleted 
                      // and cause dangling pointer, which allocated on a deleted heap memory
    
    // IntP p3(&ix); // runtime , variable ix allocated via stack, delete a stack memory is an error

    // IntP p4(new int(2048)); // legal, everything great

    IntP p2(new int(555)); // ok
    // IntP p5(p2.get()); // runtime error, double free calls, which cause an error

    return 0;
}