#include <bits/stdc++.h>
using namespace std;

vector<long long> lcmAndGcd(long long a, long long b)
{
    long long lcm, gcd;

    // first gcd
    long c = a, d = b;
    gcd = 1;
    while (c > 0 && d > 0)
    {
        if (c > d)
            c = c % d;
        else
            d = d % c;
    }
    if (c == 0)
        gcd = d;
    else
        gcd = c;

    lcm = (a * b) / gcd;
    return {lcm, gcd};
}