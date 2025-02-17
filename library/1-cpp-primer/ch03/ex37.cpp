#include <iostream>

int main()
{
    const char ca[] = "hello!";
    const char* cp = ca; // pointer to 'h'

    // here's an example of unique loop
    // char implicit converts to bool and will be true
    // if char as number will be greater than 0
    // 0 in ASCII means '/0' - end of C string
    // which means this loop ends on end of string
    // excellent, genius!
    while (*cp)
    {
        std::cout << *cp << std::endl;
        ++cp;
    }
    
    return 0;
}