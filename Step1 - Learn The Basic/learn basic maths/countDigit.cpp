#include <bits/stdc++.h>
using namespace std;

/* gfg pratice */
int evenlyDivides(int n)
{
    int cnt = 0;
    int dup = n;
    while (n > 0)
    {
        int rem = n % 10;

        if (rem != 0 && dup % rem == 0)
            cnt++;
        n = n / 10;
    }
    return cnt;
}