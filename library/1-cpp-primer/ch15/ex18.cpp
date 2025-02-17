
class Base {};

class D1 : public Base {};
class D2 : protected Base {};
class D3 : private Base {};

class DD1 : public D1 {};
class DD2 : protected D2 {};
class DD3 : private D3 {};

int main()
{
    D1 d1; D2 d2; D3 d3;
    DD1 dd1; DD2 dd2; DD3 dd3;

    Base *p = &d1; // legal
    // p = &d2; // illegal
    // p = &d3; // illegal
    p = &dd1; // legal
    // p = &dd2; // illegal
    // p = &dd3; // illegal

    return 0;
}