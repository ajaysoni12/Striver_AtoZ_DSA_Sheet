#include <bits/stdc++.h>
using namespace std;

/*
    2^16 = 2^8 * 2^8
    2^8 = 2^4 * 2^4
    2^4 = 2^2 * 2^2
    2^2 = 2^1 * 2^1
    2^1 = 2 * 2^0
*/

int binExpoRec(int a, int b)
{
    if (b == 0)
        return 1;

    long long res = binExpoRec(a, b / 2);

    if (b & 1)
        return a * res * res;
    else
        return res * res;
    /*  TC-O(n*Log2(n))
        SC-O(n*Log2(n)) */
}

int binDxpoIte(int a, int b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}