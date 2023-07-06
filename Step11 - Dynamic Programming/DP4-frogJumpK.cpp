#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f(int ind, vector<int> &cost, int k)
{
    if (ind == 0)
        return 0;

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = f(ind - j, cost, k) + abs(cost[ind] - cost[j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
    /*  TC-O(2^k) SC-O(n) */
}

/* Memoization */
int f(int ind, vector<int> &cost, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = f(ind - j, cost, k) + abs(cost[ind] - cost[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
    /*  TC-O(n*k) SC-O(n-rec + n-dp) */
}
int frogJump2(int n, vector<int> &cost, int k)
{
    vector<int> dp(n + 1, -1);
    return f(n - 1, cost, k, dp);
}

/*  Tabulation */
int frogJump2(int n, vector<int> &cost, int k)
{
    // 0-based indexing
    vector<int> dp(n, 0);

    // base case
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(cost[i] - cost[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
    /*  TC-O(n * k) SC-O(n) */
}