#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    if (n == 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
    /*  TC-O(Log(n))
        SC-O(1) */
}