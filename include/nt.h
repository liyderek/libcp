#pragma once
#include "macro.h"

vi factor(int n) {
    vi ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1) { ret.push_back(n); }
    return ret;
}

vi sieve(int n) {
    vi prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    return prime;
}

vi max_div(int n) {
    vi ret(n + 1);
    for (int i = 2; i <= n; i++) {
        if (ret[i] == 0) {
            for (int j = i; j <= n; j += i) {
                ret[j] = i;
            }
        }
    }
    return ret;
}

int phi(int n) {
    int ans = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) { n /= p; }
            ans -= ans / p;
        }
    }
    if (n > 1) { ans -= ans / n; }
    return ans;
}