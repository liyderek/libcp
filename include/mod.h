#pragma once
#include "macro.h"

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
int nck(int n, int k, vi &facts, int mod)
{
    return (facts[n] * inv((facts[k] * facts[n - k]) % mod, mod)) % mod;
}

vi compute_facts(int n, int mod)
{
    vi facts(n + 1);
    facts[0] = 1;
    for (int i = 1; i <= n; i++)
        facts[i] = (facts[i - 1] * i) % mod;
    return facts;
}

vi compute_inv(int mod)
{
    vi invs(mod);
    invs[1] = 1;
    for (int i = 2; i < mod; i++)
        invs[i] = (mod - (mod / i) * invs[mod % i] % mod) % mod;
    return invs;
}
