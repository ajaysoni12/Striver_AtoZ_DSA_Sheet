#include <bits/stdc++.h>
using namespace std;

int mod = (int)1e9 + 7;

/* recursion */
long long f1(int i, int j, int isTrue, string &exp)
{
    // base case
    if (i > j)
        return true;

    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    long long ways = 0;
    for (int ind = i + 1; ind < j; ind += 2)
    {
        long long lT = f1(i, ind - 1, 1, exp);
        long long lF = f1(i, ind - 1, 0, exp);
        long long rT = f1(ind + 1, j, 1, exp);
        long long rF = f1(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (rT * lT) % mod) % mod;
            else
                ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (rF * lF) % mod);
        }
        // xor ^
        else
        {
            // T^T = F, F^F = F, T^F = T, F^T = T
            if (isTrue)
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }
    return ways;
    /*   TC-O(expo) SC-O(n) */
}
int evaluteExp(string &exp)
{
    return f1(0, exp.size() - 1, 1, exp);
}

/* memoization */
long long f2(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    // base case
    if (i > j)
        return true;

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    long long ways = 0;
    for (int ind = i + 1; ind < j; ind += 2)
    {
        long long lT = f2(i, ind - 1, 1, exp, dp);
        long long lF = f2(i, ind - 1, 0, exp, dp);
        long long rT = f2(ind + 1, j, 1, exp, dp);
        long long rF = f2(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (rT * lT) % mod) % mod;
            else
                ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (rF * lF) % mod);
        }
        // xor ^
        else
        {
            // T^T = F, F^F = F, T^F = T, F^T = T
            if (isTrue)
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
    /*   TC-O(n*n*2) SC-O(n*n*2 + n) */
}
int evaluteExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f2(0, exp.size() - 1, 1, exp, dp);
}
