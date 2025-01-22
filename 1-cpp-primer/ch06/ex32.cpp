int& get(int* arry, int index)
{
    return arry[index]; // return reference, but not in local value
}

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i; // return an lvalue
    
    return; // forget about return statement (optional)
}

// everything is legal