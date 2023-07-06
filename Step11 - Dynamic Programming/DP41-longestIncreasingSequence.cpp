#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int prev_ind, int arr[], int n)
{
    // base case
    if (ind == n)
        return 0;

    int take_len = 0 + f1(ind + 1, prev_ind, arr, n);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        take_len = max(take_len, 1 + f1(ind + 1, ind, arr, n));

    return take_len;
    /*  TC-O(2^n) SC-O(n) */
}
int lIS(int arr[], int n)
{
    return f1(0, -1, arr, n);
}

/* memoization */
int f2(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == n)
        return 0;

    // -1 0 1 2 3
    // 0 1 2 3 4.. that why +1
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int take_len = 0 + f2(ind + 1, prev_ind, arr, n, dp);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        take_len = max(take_len, 1 + f2(ind + 1, ind, arr, n, dp));

    return dp[ind][prev_ind + 1] = take_len;
    /*  TC-O(n * n) SC-O(n * n + n) */
}
int lIS(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f2(0, -1, arr, n, dp);
}

/* tabulation */
int lIS(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // no need to write bsae case

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int take_len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take_len = max(take_len, 1 + dp[ind + 1][ind + 1]);

            dp[ind][prev_ind + 1] = take_len;
        }
    }

    return dp[0][-1 + 1];
    /*  TC-O(n*n) SC-O(n*n) */
}

/* space optimization */
int lIS(int arr[], int n)
{
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    // no need to write bsae case

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int take_len = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take_len = max(take_len, 1 + next[ind + 1]);

            curr[prev_ind + 1] = take_len;
        }
        next = curr;
    }

    return next[-1 + 1];
    /*  TC-O(n*n) SC-O(n + n) */
}

/* another method */
int lIS(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (dp[prev] < dp[i])
                dp[i] = max(dp[i], 1 + dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
    /*  TC-O(n*n) SC-O(n) */
}

/* print lis */
int* lISS(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastInd = 0;
     
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (dp[prev] < dp[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastInd = i;
        }
    }

    int list[maxi];
    list[0] = arr[lastInd];

    int ind = 1;
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        list[ind++] = arr[lastInd];
    }

    reverse(list, list + maxi);
    return list;
    /*  TC-O(n*n + n + n) SC-O(3n) */
}
