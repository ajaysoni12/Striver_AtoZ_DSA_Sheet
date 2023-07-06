#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f1(i, ind - 1, cuts) +
                   f1(ind + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
    /*  TC-O(expo) SC-O(n) */
}
int minCost(int stickLen, int n, vector<int> &cuts)
{
    cuts.push_back(stickLen);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    return f1(1, n, cuts);
}

/* memoization */
int f2(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f2(i, ind - 1, cuts, dp) +
                   f2(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
    /*  TC-O(n*n * n) SC-O(n*n + n) */
}
int minCost(int stickLen, int n, vector<int> &cuts)
{
    cuts.push_back(stickLen);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f2(1, n, cuts, dp);
}

/* tabulation */
int minCost(int stickLen, int n, vector<int> &cuts)
{
    cuts.push_back(stickLen);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(2 + 1, vector<int>(n + 2, 0));

    // no need of base case

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] +
                           dp[ind + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n]; 
}