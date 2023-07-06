
#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int ind, int W, vector<int> &wt, vector<int> &val)
{
    // base case
    if (ind == 0)
    {
        if (wt[ind] <= W)
            return val[ind];
        return 0;
    }

    // try out all two options
    int notTake = 0 + f1(ind - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f1(ind - 1, W - wt[ind], wt, val);

    return max(notTake, take);
    /*  TC-O(2^n) SC-O(n-rec) */
}
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    return f1(n - 1, W, wt, val);
}

/* Memoization  */
int f2(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
        if (wt[ind] <= W)
            return val[ind];
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    // try out all two options
    int notTake = 0 + f2(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f2(ind - 1, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(notTake, take);
    /*  TC-O(n*w) SC-O(n*w + n-rec) */
}
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f2(n - 1, W, wt, val, dp);
}

/* Tabulation */
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base case
    for (int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind - 1][w - wt[ind]];

            dp[ind][w] = max(notTake, take);
        }
    }

    return dp[n - 1][W];
    /*  TC-O(n*W) SC-O(n*W) */
}

/* space optimization - using two array */
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];

            curr[w] = max(notTake, take);
        }
        prev = curr;
    }

    return prev[W];
    /*  TC-O(n*W) SC-O(W + W) */
}

/* space otpimization - using single array */
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0);

    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = W; w >= 0; w--)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];

            prev[w] = max(notTake, take);
        }
    }

    return prev[W];
    /*  TC-O(n*W) SC-O(W + W) */
}