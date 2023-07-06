#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int n, vector<int> &cost)
{
    // base case, from 0->0 cost you 0
    if (n == 0)
        return 0;

    // take one step
    int left = f1(n - 1, cost) + abs(cost[n] - cost[n - 1]);

    // either take two step
    int right = INT_MAX;
    if (n > 1)
        right = f1(n - 2, cost) + abs(cost[n] - cost[n - 2]);

    // minimum cost
    return min(left, right);
}
int frogJump(int n, vector<int> &cost)
{
    return f1(n - 1, cost);
    /*  TC-O(2^n) SC-O(n) */
}

/* Memoization */
int f2(int n, vector<int> &cost, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    // take one step
    int left = f2(n - 1, cost, dp) + abs(cost[n] - cost[n - 1]);
    // or take two step
    int right = INT_MAX;
    if (n > 1)
        right = f2(n - 2, cost, dp) + abs(cost[n] - cost[n - 2]);

    // find minimum amount
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &cost)
{
    vector<int> dp(n + 1, -1);
    return f2(n - 1, cost, dp);
    /*  TC-O(n - linear eqn) SC-O(n-rec + n-dp) */
}

/* Tabulation */
int frogJump(int n, vector<int> &cost)
{
    vector<int> dp(n, 0); // 0-based indexing

    // base case
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[n - 1] + abs(cost[i] - cost[i - 1]);

        int ss = INT_MAX;
        if (i > 1)
            ss = dp[n - 2] + abs(cost[i] - cost[i - 2]);

        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
    /*  TC-O(n) SC-O(n - dp) */
}

/* Space Optimization */
int frogJump(int n, vector<int> &cost)
{

    // base case
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = prev1 + abs(cost[i] - cost[i - 1]);

        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(cost[i] - cost[i - 2]);

        int curri = min(fs, ss);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
    /*  TC-O(n) SC-O(1) */
}