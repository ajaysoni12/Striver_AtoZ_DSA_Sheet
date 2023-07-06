#include <bits/stdc++.h>
using namespace std;
/* House Robber 1 *
/
/* Recursion */
int f1(int ind, vector<int> &arr)
{
    if (ind == 0)
        return arr[ind];

    if (ind < 0)
        return 0;

    int pick = arr[ind] + f1(ind - 2, arr);
    int notPick = 0 + f1(ind - 1, arr);
    return max(pick, notPick);
    /*  TC-O(2^n) SC-O(n) */
}

/* Memoization */
int f2(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int pick = arr[ind] + f2(ind - 2, arr, dp);
    int notPick = 0 + f2(ind - 1, arr, dp);
    return dp[ind] = max(pick, notPick);
    /*  TC-O(n-Linear) SC-O(n-rec + n-dp) */
}
int maxSumFromAdjEle(vector<int> &arr, int n)
{
    vector<int> dp(n, -1);
    return f2(n - 1, arr, dp);
}

/* Tabulation */
int maxSumFromAdjEle(vector<int> &arr, int n)
{
    vector<int> dp(n, 0);

    // base case
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];
        int notTake = 0 + dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}

/* Space Optimization */
int maxSumFromAdjEle(vector<int> &arr, int n)
{
    // base case
    int prev2 = 0;
    int prev1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int notTake = 0 + prev1;
        int curri = max(take, notTake);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
    /*  TC-O(n) SC-O(1) */
}
