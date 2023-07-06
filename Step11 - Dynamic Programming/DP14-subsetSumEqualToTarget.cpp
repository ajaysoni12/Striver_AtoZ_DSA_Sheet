#include <bits/stdc++.h>
using namespace std;

/* Recursion */
bool f1(int ind, int target, vector<int> &arr)
{
    // target will achieve
    if (target == 0)
        return true;

    // base case
    if (ind == 0)
        return arr[0] == target;

    // try all options
    int notTake = f1(ind - 1, target, arr);
    int take = false;
    if (target >= arr[ind])
        take = f1(ind - 1, target - arr[ind], arr);

    return notTake | take;
    /*  TC-O(2^n) SC-O(n) */
}
bool subsetSumK(int n, int k, vector<int> &arr)
{
    return f1(n - 1, k, arr);
}

/* Memoization - overlapping subproblem */
bool f2(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // target will achieve
    if (target == 0)
        return true;

    // base case
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    // try all options
    int notTake = f2(ind - 1, target, arr, dp);
    int take = false;
    if (target >= arr[ind])
        take = f2(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTake | take;
    /*  TC-O(n*target) SC-O(n-rec + n*target) */
}
bool subsetSumK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f2(n - 1, k, arr, dp);
}

/* Tabulation */
bool subsetSumK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // for target equal to
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = true;

    // for ind equal to
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTake = dp[ind - 1][target];
            int take = false;
            if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTake | take;
        }
    }

    // where our call start
    return dp[n - 1][k];

    /*  TC-O(n*k) SC-O(n*k) */
}

/* space optimization */
bool subsetSumK(int n, int k, vector<int> &arr)
{
    // vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);

    /*
        // for target equal to
        for (int ind = 0; ind < n; ind++)
            dp[ind][0] = true;
    */
    prev[0] = curr[0] = true; // for target 0, mark true

    /*
        // for ind equal to
        dp[0][arr[0]] = true;
    */

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTake = prev[target];
            int take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];

            curr[target] = notTake | take;
        }
        prev = curr;
    }

    // where our call start
    return prev[k];

    /*  TC-O(n*k) SC-O(k + k) */
}
