#include <bits/stdc++.h>
using namespace std;

/*  Recursion */
int f1(int ind, int tar, vector<int> &arr)
{
    // target will achieve
    if (tar == 0)
        return 1;

    // base case
    if (ind == 0)
        return arr[0] == tar;

    // try out all possible way
    int notTake = f1(ind - 1, tar, arr);
    int take = 0;
    if (tar >= arr[ind])
        take += f1(ind - 1, tar - arr[ind], arr);

    return notTake + take;
    /*  TC-O(2^n) SC-O(n) */
}
int cntSubsetWithSumK(vector<int> &arr, int tar)
{
    return f1(arr.size() - 1, tar, arr);
}

/* Memoization - overlapping subproblem */
int f2(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    // target will achieve
    if (tar == 0)
        return 1;

    // base case
    if (ind == 0)
        return arr[0] == tar;

    if (dp[ind][tar] != -1)
        return dp[ind][tar];

    // try out all possible way
    int notTake = f2(ind - 1, tar, arr, dp);
    int take = 0;
    if (tar >= arr[ind])
        take += f2(ind - 1, tar - arr[ind], arr, dp);

    return dp[ind][tar] = notTake + take;
    /*  TC-O(n*target) SC-O(n*target + n) */
}
int cntSubsetWithSumK(vector<int> &arr, int tar)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f2(n - 1, tar, arr, dp);
}

/* Tabulation */
int cntSubsetWithSumK(vector<int> &arr, int tar)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // base case
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = 1;

    if (arr[0] <= tar)
        dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][tar];
            int take = 0;
            if (tar >= arr[ind])
                take += dp[ind - 1][tar - arr[ind]];

            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n - 1][tar];
    /*  TC-O(n * tar) SC-O(n * tar) */
}

/* space optiization */
int cntSubsetWithSumK(vector<int> &arr, int tar)
{
    int n = arr.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

    // base case
    prev[0] = curr[0] = 1;

    curr[0] = 1;

    if (arr[0] <= tar)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[tar];
            int take = 0;
            if (tar >= arr[ind])
                take += prev[tar - arr[ind]];

            curr[sum] = notTake + take;
        }
        prev = curr;
    }
    return prev[tar];
    /*  TC-O(n * tar) SC-O(2 * tar) */
}

// for 0 case
int f2(int ind, int tar, int arr[], vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
        if (tar == 0 && arr[0] == 0)
            return 2;
        if (tar == 0 || arr[0] == tar)
            return 1;
        return 0;
    }

    if (dp[ind][tar] != -1)
        return dp[ind][tar];

    // try out all possible way
    int notTake = f2(ind - 1, tar, arr, dp);
    int take = 0;
    if (tar >= arr[ind])
        take += f2(ind - 1, tar - arr[ind], arr, dp);

    return dp[ind][tar] = (notTake + take);
    /*  TC-O(n*target) SC-O(n*target + n) */
}