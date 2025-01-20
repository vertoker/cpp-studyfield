#include <iostream>

void swap(int*& a, int*& b)
{
    int* temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    
    std::cout << "pa = " << pa << ", pb = " << pb << std::endl;
    swap(pa, pb);
    std::cout << "pa = " << pa << ", pb = " << pb << std::endl;
    
    return 0;
}