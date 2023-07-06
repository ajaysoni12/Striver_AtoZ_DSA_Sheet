#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int W, vector<int> &wt, vector<int> &val)
{
    // base case
    if (ind == 0)
        return ((int)(W / wt[0])) * val[0];

    int notTake = 0 + f1(ind - 1, W, wt, val);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + f1(ind, W - wt[ind], wt, val);

    return max(take, notTake);
    /*  TC-O(>>2^n-expo) SC-O(W) */
}
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    return f1(n - 1, W, wt, val);
}

/* memoization */
int f2(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
        return ((int)(W / wt[0])) * val[0];

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTake = 0 + f2(ind - 1, W, wt, val, dp);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + f2(ind, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(take, notTake);
    /*  TC-O(ind*W) SC-O(ind*W + W) */
}
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f2(n - 1, W, wt, val, dp);
}

/* tabulation */
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base case
    for (int w = 0; w <= W; w++)
        dp[0][w] = ((int)w / wt[0]) * val[0];

    // changing parameter
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + dp[ind - 1][W];
            int take = 0;
            if (wt[ind] <= W)
                take = val[ind] + dp[ind][W - wt[ind]];

            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
    /*  TC-O(n*W) SC-O(n*W) */
}

/* space optimization */
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // base case
    for (int w = 0; w <= W; w++)
        prev[w] = ((int)w / wt[0]) * val[0];

    // changing parameter
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + prev[w];
            int take = 0;
            if (wt[ind] <= w)
                take = val[ind] + curr[w - wt[ind]];

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[W];
    /*  TC-O(n*W) SC-O(W + W) */
}

/* further space optimization */
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(W + 1, 0);

    // base case
    for (int w = 0; w <= W; w++)
        prev[w] = ((int)w / wt[0]) * val[0];

    // changing parameter
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + prev[w];
            int take = 0;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];

            prev[w] = max(take, notTake);
        }
    }

    return prev[W];
    /*  TC-O(n*W) SC-O(W) */
}
