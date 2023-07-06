#include <bits/stdc++.h>
using namespace std;

const int size = 1e9 + 10;
vector<bool> isPrime(size, 1);

bool printPrime(int n)
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < size; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < size; j+=i)
                isPrime[j] = false;
        }
    }

    if (isPrime[n] == true)
        return true;
    return false;
    /*  TC-O(n*Log(Log(n))) */
}
