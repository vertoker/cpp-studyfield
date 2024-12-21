#include <string>

int main()
{
    int i;
    double d;
    const std::string somedata = "some data";
    const std::string* cs = &somedata;
    char* pc;
    void* pv;

    // yes, order for no segfault
    pv = static_cast<void*>(&cs); // a
    pc = static_cast<char*>(pv); // d
    i = static_cast<int>(*pc); // b
    pv = static_cast<void*>(&pc); // c

    return 0;
}