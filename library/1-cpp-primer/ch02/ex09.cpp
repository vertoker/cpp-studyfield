#include <iostream>

int main()
{
    // uninitialized, therefore undefined
    unsigned long long undefined;
    std::cout << undefined << std::endl;
    
    //std::cin >> int input_value; // incorrect
    int input_value; // first initialization
    std::cin >> input_value; // then input

    //int i = {3.14}; // implicit conversion not work
    int i = 3.14; // implicit conversion

    //double salary = wage = 9999.99; // incorrect
    double salary = 9999.99, wage = salary; // correct

    return 0;
}