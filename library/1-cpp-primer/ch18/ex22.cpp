#include <iostream>

class A {};
class B : public A{};
class C : public B{};

class X {};
class Y {};
class Z : public X, public Y {};

class MI : public C, public Z {};
class D : public X, public C{};

// In order A, B, C, X, Y, Z, MI, D or appearance order

MI mi;

int main()
{
    D* pd = new D;
    X* px = pd;
    B* pb = pd;
    A* pa = pd;
    C* pc = pd;

    return 0;
}