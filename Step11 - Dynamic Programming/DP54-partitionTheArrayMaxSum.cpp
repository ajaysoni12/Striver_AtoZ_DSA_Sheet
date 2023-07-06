#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, vector<int> &nums, int k)
{
    int n = nums.size();
    if (ind == n)
        return 0;

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, nums[j]);
        int sum = maxi * len + f1(j + 1, nums, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
    /*  TC-O(expo) SC-O(n) */
}
int maximumSubarray(vector<int> &nums, int n, int k)
{
    return f1(0, nums, k);
}

/* memoization */
int f2(int ind, vector<int> &nums, int k, vector<int> &dp)
{
    int n = nums.size();
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, nums[j]);
        int sum = maxi * len + f2(j + 1, nums, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
    /*  TC-O(n * k) SC-O(n + n) */
}
int maximumSubarray(vector<int> &nums, int n, int k)
{
    vector<int> dp(n, -1);
    return f2(0, nums, k, dp);
}

/* tabulation */
int maximumSubarray(vector<int> &nums, int n, int k)
{
    vector<int> dp(n + 1, 0);

    // base caes
    dp[n] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, nums[j]);
            int sum = maxi * len + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }

    return dp[0];
    /*  TC-O(n*k) SC-O(n) */
}
