// 5. Know what functions C++ silently writes and calls

// Next classes are identical

class Empty1 {};

class Empty2
{
public:
    Empty2() { }
    ~Empty2() { }

    Empty2(const Empty2& rhs) { }
    Empty2& operator=(const Empty2& rhs) { }
};
