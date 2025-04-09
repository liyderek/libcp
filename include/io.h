#pragma once
#include "macro.h"

void openfile(string s)
{
    freopen((s + string(".in")).c_str(), "r", stdin);
    freopen((s + string(".out")).c_str(), "w", stdout);
}
