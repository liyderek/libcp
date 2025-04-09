#pragma once
#include "macro.h"

vi compute_derangements(int n, int mod)
{
    vi ret(n + 1);
    ret[0] = 1;
    ret[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        ret[i] = (i - 1) * (ret[i - 1] + ret[i - 2]) % mod;
    }
    return ret;
}