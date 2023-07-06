#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops)  */
vector<int> findAndMissingNum(vector<int> &num, int n)
{
    int missing = -1, repeat = -1;

    // no. from 1 to n
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (num[j] == i)
                cnt++;
        }

        // cnt == 2, then it is repeating number
        if (cnt == 2)
            repeat = i;

        // cnt == 0, then it is missing number
        if (cnt == 0)
            missing = i;

        // if both num find then break out from loop
        if (missing != -1 and repeat != -1)
            break;
    }
    return {repeat, missing};
    /*  TC-O(n*n = n^2)
        SC-O(1) */
}

/* method 2 (better approach: using hashing) */
vector<int> findAndMissingNum(vector<int> &num, int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
        hash[num[i]]++;

    int repeat = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeat = i;
        if (hash[i] == 0)
            missing = i;

        if (repeat != -1 and missing != -1)
            break;
    }
    return {repeat, missing};
    /*  TC-O(n + n = 2n)
        SC-O(n) */
}

/* method 3 (optimize solution 1: using maths) */
vector<int> findAndMissingNum(vector<int> &num, int n)
{
    /*
        steps:
            1) take s1 summision and sn1-sum of first n natural num summision(formula: (n*(n+1))/2)

            2) take s2 square of given num and sn2 - sum of square of first n natural num(formula: n*(n+1)*(n*2+1)/6)

            3) s1 - sn1 = .... or x - y = ... eqn(1)
            4) s2^2 - sn2^2 = .... or x^2 - y^2 = ...
            5) and (x+y)(x-y) = .... then reaplace value then genrate second eqn(2)
            6) find value of x(repeating) and y(missing) num
    */

    // s1 - sn1
    // s2 - sn2

    // sum of first n natural num
    long long sn1 = (n * (n + 1)) / 2;

    // sum of square of first n natural num
    long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s1 = 0, s2 = 0;

    for (int i = 0; i < n; i++)
    {
        s1 += num[i];
        s2 += (long long)num[i] * (long long)num[i];
    }

    long long val1 = s1 - sn1; // x - y
    long long val2 = s2 - sn2;
    val2 = val2 / val1; // x + y = val2/(x-y), x + y

    long long x = (val1 + val2) / 2; // repeating
    long long y = x - val1;          // missing

    return {(int)x, (int)y};
    /*  TC-O(n)
        SC-O(1) */
}

/* method 3 (optimized solution 2: using x-or property) */
vector<int> findAndMissingNum(vector<int> &num, int n)
{
    /*
        steps:
            1) do x-or of arr[i] and do xor of natrual mum till n
            2) find first set bit from msb side
            3) put them into two parts and do xor
    */

    // step1: find number
    int _xor = 0;
    for (int i = 0; i < n; i++)
    {
        _xor ^= num[i];
        _xor ^= (i + 1);
    }

    // step2: find set bit index from msb site
    // number = xor & ~(xor - 1)
    int bitNo = 0;
    while (true)
    {
        if ((_xor & (1 << bitNo)) != 0)
            break;
        bitNo++;
    }

    // step3: divide into two club, 0 and 1
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of 1st club
        if ((num[i] & (1 << bitNo)) != 0)
            one = one ^ num[i];

        // part of 0'th club
        else
            zero = zero ^ num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // part of 1st club
        if ((i & (1 << bitNo)) != 0)
            one = one ^ i;

        // part of 0'th club
        else
            zero = zero ^ i;
    }

    // step4: just confirm
    int cnt = 0;
    for (int i = 1; i < n; i++)
        if (num[i] == zero)
            cnt++;

    if (cnt == 2)
        return {zero, one};
    return {one, zero};

    /*  TC-O(n - near about) 
        SC-O(1) */
}
