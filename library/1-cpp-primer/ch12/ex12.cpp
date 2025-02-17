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
    auto p = new int();
    auto sp = std::make_shared<int>();
    
    process(sp); // legal, usual copy
    
    //process(new int()); // illegal, shared_ptr doesn't have costructor for that
    
    //process(p); // illegal, shared_ptr can't construct that implicitly
    
    process(std::shared_ptr<int>(p)); // legal, pointer have constructor, but I'd rather don't do this
    
    return 0;
}