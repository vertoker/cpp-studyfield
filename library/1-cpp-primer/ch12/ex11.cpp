#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function: " << ptr.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<int> p(new int(42));
    // where "double free error" is generated
    process(std::shared_ptr<int>(p.get()));
    
    return 0;
}