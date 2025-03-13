// 4. Make sure that objects are initialized before they're used

// this can be produced by several tricks

class ChillGuy
{
    // 1. by default initialization inside class
    int i1 = 1;
    double d2 = 2.0;
    char c3 = '3';

    ChillGuy() : i1{}, d2{}, c3{} { } // 2. by default initialization inside constructor
    ChillGuy(int i1, double d2, char c3) : i1{i1}, d2{d2}, c3{c3} { } // 3. by initialization of ALL elements
};

