#include <bits/stdc++.h>

using namespace std;

// Macro to create a multi-dimensional vector
#define vec(type, ...) createVec<type>(__VA_ARGS__)

// Base case for 1D vector
template <typename T> vector<T> createVec(size_t n, T val)
{
    return vector<T>(n, val);
}

// Recursive case for multi-dimensional vector
template <typename T, typename... Args> auto createVec(size_t n, Args... args)
{
    return vector<decltype(createVec<T>(args...))>(n, createVec<T>(args...));
}

auto test = vec(int, 2, 3, -1);

int main()
{
    // debug test
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
}
