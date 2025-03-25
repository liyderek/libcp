#pragma once
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
