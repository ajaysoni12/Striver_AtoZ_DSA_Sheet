#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[k - 1] * arr[k] + arr[j] + f1(i, k, arr) +
                    f1(k + 1, j, arr);
        if (steps < mini)
            mini = steps;
    }
    return mini;
    /*  TC-O(expo) SC-O(n) */
}
int MCM(vector<int> &arr, int n)
{
    return f1(1, n - 1, arr);
}

/* memoization */
int f2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[k - 1] * arr[k] + arr[j] + f1(i, k, arr) +
                    f1(k + 1, j, arr);
        if (steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
    /*  TC-O(n*n * n) SC-O(n*n + n) */
}
int MCM(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f2(1, n - 1, arr, dp);
}

/* tabulation */
int MCM(vector<int> &arr, int n)
{
    int dp[n][n];

    // base caes
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini; 
        }
    }

    return dp[1][n - 1]; 
    /*  TC-O(n^3) SC-O(n*n) */
}
