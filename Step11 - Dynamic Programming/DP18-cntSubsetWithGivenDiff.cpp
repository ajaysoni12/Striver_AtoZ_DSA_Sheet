#include <bits/stdc++.h>
using namespace std;

int f2(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
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
int findWays(vector<int> &arr, int tar)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f2(n - 1, tar, arr, dp);
}

int cntPartition(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum - d < 0 || totSum % 2)
        return false;

    return findWays(arr, (totSum - d) / 2); // return mod
}

// Tabulation
bool cntPartition2(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum - d < 0 || totSum - d % 2)
        return false;

    int k = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // base case
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1; 

    // for ind equal to, 5- mark true, but 0 not run 
    if (arr[0] != 0 && arr[0] <= k)
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
