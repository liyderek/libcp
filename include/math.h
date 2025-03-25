#pragma once
#include <bits/stdc++.h>

using namespace std;

int binpow(int b, int p, int mod)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return res;
}

// Modular Inverse
int inv(int b, int mod)
{
    return binpow(b, mod - 2, mod);
}

// Binomial Coefficients
int nCr(int n, int r, vector<int> &facts, int mod)
{
    return (facts[n] * inv((facts[r] * facts[n - r]) % mod, mod)) % mod;
}

// Geometry
// Distance Formula
double distanceab(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
