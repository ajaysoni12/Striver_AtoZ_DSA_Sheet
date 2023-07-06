#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, vector<int> &arr)
{
    // base case
    if (i > j)
        return 0;

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] +
                   f1(i, ind - 1, arr) + f1(ind + 1, j, arr);
        maxi = max(maxi, cost);
    }
    return maxi;
    /*  TC-O(expo) SC-O(n) */
}
int burstBallon(vector<int> &ballons)
{
    int n = ballons.size();
    ballons.push_back(1);
    ballons.insert(ballons.begin(), 1);

    return f1(1, n, ballons);
}

/* memoization */
int f2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1] +
                   f2(i, ind - 1, arr, dp) + f2(ind + 1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
    /*  TC-O(n* * nn) SC-O(n*n + n) */
}
int burstBallon(vector<int> &ballons)
{
    int n = ballons.size();
    ballons.push_back(1);
    ballons.insert(ballons.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return f2(1, n, ballons, dp);
}

/* tabulation */
int burstBallon(vector<int> &arr)
{
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = arr[i - 1] * arr[ind] * arr[j + 1] +
                           dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
    /*  TC-O(n*n * n) SC-O(n*n) */
}
