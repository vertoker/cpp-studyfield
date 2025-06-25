
class B;

class A
{
    B* ptr;
};
class B
{
    A* ptr;
};

int main()
{
    A* a = nullptr;
    B* b = 0;
    delete a;
    delete b;

    return 0;
}