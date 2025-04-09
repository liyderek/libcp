#pragma once
#include "macro.h"

// Overload operator >> for vector<T>
template <typename T> istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &elem : v)
    {
        in >> elem;
    }
    return in;
}

// Overload operator << for vector<T>
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const auto &elem : v)
    {
        out << elem << " ";
    }
    return out;
}
