#include <bits/stdc++.h>
using namespace std;

long long sumOfDivisors(int n)
{
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int sumOfFactors = 0;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                sumOfFactors += j;
                if ((i / j) != j)
                    sumOfFactors += i / j;
            }
        }
        ans += sumOfFactors;
    }
    return ans;
}

long long sumOfDivisors(int n)
{
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = ans + (n / i) * i;
    }
    return ans;
}