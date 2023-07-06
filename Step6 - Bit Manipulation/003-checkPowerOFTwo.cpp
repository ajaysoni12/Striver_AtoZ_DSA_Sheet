#include <bits/stdc++.h>
using namespace std;

bool powOf2(int n)
{
    if (n & (n - 1))
        return true;
    return false;
}