// Module header. Using only for study cases
// Sources
// https://en.cppreference.com/w/cpp/language/modules.html
// https://www.youtube.com/watch?v=LvRQH8Gkl1E

module; // global module

#include <iostream>

export module testmodule;

int foo() { return 1; }
export int bar() { return foo() + 1; }

export void print() { std::cout << (bar() + 1); }
