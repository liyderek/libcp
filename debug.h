#pragma once
#include <bits/stdc++.h>

using namespace std;

constexpr const char *red = "\033[38;2;243;139;168m";
constexpr const char *green = "\033[38;2;166;227;161m";
constexpr const char *blue = "\033[38;2;180;190;254m";
constexpr const char *pink = "\033[38;2;245;194;231m";

constexpr const char *res = "\x1B[0m";

#ifdef MEN
struct DebugStream
{
    string color = string(pink);

    void col(const char *c)
    {
        color = string(c);
    }

    template <typename T> DebugStream &operator<<(const T &value)
    {
        cout << color << value << res;
        return *this;
    }

    DebugStream &operator<<(ostream &(*manip)(ostream &))
    {
        cout << manip;
        return *this;
    }

    template <typename T, template <typename, typename> class Container, typename Alloc>
    DebugStream &operator<<(const Container<T, Alloc> &container)
    {
        cout << color << "{";
        bool first = true;
        for (const auto &elem : container)
        {
            if (!first)
                cout << ", ";
            cout << elem;
            first = false;
        }
        cout << "}" << res;
        return *this;
    }
} dbg;
#else
struct NullStream
{
    template <typename T> NullStream &operator<<(const T &)
    {
        return *this;
    }
    NullStream &operator<<(ostream &(*)(ostream &))
    {
        return *this;
    }
    void col(const char *c)
    {
    }
} dbg;
#endif
