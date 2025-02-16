
class Base
{
public:
    int public_member;
protected:
    int protected_member;
private:
    int private_member;
};

class D1 : public Base
{
    int f1() { return public_member; } // ok
    int f2() { return protected_member; } // ok
    //int f3() { return private_member; } // error
};
class D2 : protected Base
{
    int f1() { return public_member; } // ok
    int f2() { return protected_member; } // ok
    //int f3() { return private_member; } // error
};
class D3 : private Base
{
    int f1() { return public_member; } // ok
    int f2() { return protected_member; } // ok
    //int f3() { return private_member; } // error
};

class D11 : public D1 // : public Base
{
    int f1() { return public_member; } // ok
    int f2() { return protected_member; } // ok
    //int f3() { return private_member; } // error
};
class D21 : public D2 // : protected Base
{
    int f1() { return public_member; } // ok
    int f2() { return protected_member; } // ok
    //int f3() { return private_member; } // error
};
class D31 : public D3 // : private Base
{
    //int f1() { return public_member; } // error
    //int f2() { return protected_member; } // error
    //int f3() { return private_member; } // error
};