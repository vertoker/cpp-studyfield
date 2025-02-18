
template <typename T>
auto sum(T a, T b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    auto s = sum(2000000000, 2000000000);
    return 0;
}