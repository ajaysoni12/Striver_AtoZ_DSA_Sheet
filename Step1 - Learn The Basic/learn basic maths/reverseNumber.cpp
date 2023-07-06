#include <bits/stdc++.h>
using namespace std;

long long reversedBits(long long x)
{
    long long ans = 0;
    int index = 31;
    while (x > 0)
    {
        if (x % 2 == 1)
            ans += pow(2, index);
        index--;
        x = x / 2;
    }
    return ans;
}