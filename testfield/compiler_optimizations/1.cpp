#include <iostream>

class A
{
public:
    A() { std::cout << "default" << std::endl; }
    A(const A&) { std::cout << "copy" << std::endl; }
    A(A&&) { std::cout << "move" << std::endl; }
};

A RVO()
{
    return A{};
}
A NRVO()
{
    A a;
    return a;
}

A NRVO_broke()
{
    if (false)
    {
        A a2;
        return a2;
    }

    A a;
    return a;
}

A NRVO_move()
{
    A a;
    return std::move(a);
}

A NRVO_move_correct()
{
    if (false)
    {
        A a2;
        return a2;
    }

    A a;
    return a;
}

A NRVO_ref(const A& a)
{
	return a;
}

A NRVO_local(A a)
{
	return a;
}

int main()
{
    std::cout << "a1 - RVO" << std::endl;
    A a1 = RVO();
    std::cout << "a2 - NRVO" << std::endl;
    A a2 = NRVO();
    std::cout << "a3 - NRVO_broke" << std::endl;
    A a3 = NRVO_broke();
    std::cout << "a4 - NRVO_move" << std::endl;
    A a4 = NRVO_move();
    std::cout << "a5 - NRVO_move_correct" << std::endl;
    A a5 = NRVO_move_correct();
    std::cout << "a6 - NRVO_ref" << std::endl;
    A a6 = NRVO_ref(a1);
    std::cout << "a7 - NRVO_local" << std::endl;
    A a7 = NRVO_local(a1);
    return 0;
}