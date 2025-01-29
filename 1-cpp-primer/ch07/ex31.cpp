struct X;
struct Y;

struct X
{
    Y* y;
};
struct Y
{
    X x;
};
