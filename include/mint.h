#pragma once
#include "macro.h"

template<int32_t MOD> struct modint {
    static const int mod = MOD;
    int32_t v; explicit operator int32_t() const { return v; } // explicit -> don't silently convert to int
    modint():v(0) {}
    modint(int _v) { v = int32_t((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    bool operator==(const modint& o) const {
        return v == o.v; }
    friend bool operator!=(const modint& a, const modint& b) {
        return !(a == b); }
    friend bool operator<(const modint& a, const modint& b) {
        return a.v < b.v; }
    friend string ts(modint a) { return to_string(a.v); }

    modint& operator+=(const modint& o) {
        if ((v += o.v) >= MOD) v -= MOD;
        return *this; }
    modint& operator-=(const modint& o) {
        if ((v -= o.v) < 0) v += MOD;
        return *this; }
    modint& operator*=(const modint& o) {
        v = int32_t((int)v*o.v%MOD); return *this; }
    modint& operator/=(const modint& o) { return (*this) *= inv(o); }
    friend modint pow(modint a, int p) {
        modint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend modint inv(const modint& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    modint operator-() const { return modint(-v); }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }
};