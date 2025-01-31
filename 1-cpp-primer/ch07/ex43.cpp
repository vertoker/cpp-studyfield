
class NoDefault
{
    int i;
public:
    NoDefault(int i) : i(i) { }
};

class C
{
    NoDefault noDefault;
public:
    C() : noDefault(0) { }
};
