#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int n)
{
    // if n == 0, or n == 1, return 1 steps
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    // take 1 steps
    int left = f1(n - 1);

    // take 2 steps
    int right = f1(n - 2);

    // total way
    return (left + right) % (1000000007);
}
int countWays(int n)
{
    return f1(n) % 1000000007;
    /*  TC-O(2^n) SC-O(n) */
}

/*  Memoization(Top Down) */
int f2(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    // take 1 steps
    int left = f2(n - 1, dp);
    // take 2 stpes
    int right = f2(n - 2, dp);

    // return total ways
    return dp[n] = (left + right) % (1000000007);
}
int countWays(int n)
{
    vector<int> dp(n + 1, -1);
    return f2(n, dp) % 1000000007;
    /*  TC-O(n-linear computation) SC-O(n-rec + n-dp) */
}

/* Tabulation(Bottom Up) */
int f3(int n, vector<int> &dp)
{
    // base case
    dp[0] = dp[1] = 1;

    // for 2 you will start 
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    // return for nth
    return dp[n];
}
int countWays(int n)
{
    vector<int> dp(n + 1, -1);
    return f3(n, dp) % 1000000007;
    /*  TC-O(n) SC-O(n-dp) */
}

/* Space Optimization */
int f4(int n)
{
    // base case
    int prev2 = 1;
    int prev1 = 1;

    // for 2 you will start 
    for (int i = 2; i <= n; i++)
    {
        int curi = (prev1 + prev2) % 1000000007;
        prev2 = prev1; 
        prev1 = curi; 
    }
    
    // return for nth
    return prev1;
}
int countWays(int n)
{
    return f4(n) % 1000000007;
    /*  TC-O(n) SC-O(n-dp) */
}