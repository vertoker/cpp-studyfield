#include <iostream>

int main()
{
    int yes = 1, no = 0;
    int *pi1 = nullptr;
    int *pi2 = &yes, *pi3 = &no;

    // nullptr check
    if (pi3) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;

    // nullptr check
    if (pi1) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;

    // implicit bool, 1 = true, 0 = false
    if (yes) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;

    // implicit bool, 1 = true, 0 = false
    if (no) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;

    // Overall answers is: yes no yes no

    return 0;
}