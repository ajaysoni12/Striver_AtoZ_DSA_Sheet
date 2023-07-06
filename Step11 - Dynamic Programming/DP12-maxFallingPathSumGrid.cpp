#include <bits/stdc++.h>
using namespace std;

/* Recursion(top - down) */
int f1(int i, int j, vector<vector<int>> &grid)
{
    // out of bound case
    if (j < 0 || j >= grid[0].size())
        return -1e9;

    // base case
    if (i == 0)
        return grid[0][j];

    // try out all possible way
    int left_d = grid[i][j] + f1(i - 1, j - 1, grid);
    int upper = grid[i][j] + f1(i - 1, j, grid);
    int right_d = grid[i][j] + f1(i - 1, j + 1, grid);
    return max(left_d, max(upper, right_d));
    /*  TC-O(3^n-only n because you can go linear, one by one)
        SC-O(n) */
}
int maxFallingPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int maxi = -1e9;

    // try out for all column
    for (int j = 0; j < m; j++)
        maxi = max(maxi, f1(n - 1, j, grid));
    return maxi;
    /*  TC-O(m * f2 fun tc * n) SC-O(f2 fun sc) */
}

/* Memoization (Overlapping-SubProblem) */
int f2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // out of bound case
    if (j < 0 || j >= grid[0].size())
        return -1e9;

    // base case
    if (i == 0)
        return grid[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    // try out all possible way
    int left_d = grid[i][j] + f2(i - 1, j - 1, grid, dp);
    int upper = grid[i][j] + f2(i - 1, j, grid, dp);
    int right_d = grid[i][j] + f2(i - 1, j + 1, grid, dp);
    return dp[i][j] = max(left_d, max(upper, right_d));
    /*  TC-O(n*m) SC-O(n-rec + n*m-dp) */
}
int maxFallingPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e9;

    // try out for all column
    for (int j = 0; j < m; j++)
        maxi = max(maxi, f2(n - 1, j, grid, dp));
    return maxi;
    /*  TC-O(m * f2 fun tc ) SC-O(f2 fun sc) */
}

/* Tabulation(bottom-up) */
int maxFallingPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxi = -1e9;

    // base case
    for (int j = 0; j < m; j++)
        dp[0][j] = grid[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // try out all possible way
            int left_d = grid[i][j];
            if (j > 0)
                left_d += dp[i - 1][j - 1];
            else
                left_d += (-1e9);

            int upper = grid[i][j] + dp[i - 1][j];

            int right_d = grid[i][j];
            if (j < m - 1)
                right_d += dp[i - 1][j + 1];
            dp[i][j] = max(left_d, max(upper, right_d));
        }
    }

    // try out for all column
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);
    return maxi;
    /*  TC-O(m + n*m) SC-O(n*m) */
}

/* space optimization */
int maxFallingPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);
    int maxi = -1e9;

    // base case
    for (int j = 0; j < m; j++)
        prev[j] = grid[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            // try out all possible way
            int left_d = grid[i][j];
            if (j > 0)
                left_d += prev[j - 1];
            else
                left_d += (-1e9);

            int upper = grid[i][j] + prev[j];

            int right_d = grid[i][j];
            if (j < m - 1)
                right_d += prev[j + 1];
            curr[j] = max(left_d, max(upper, right_d));
        }
        // update prev
        prev = curr;
    }

    // try out for all column
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);
    return maxi;
    /*  TC-O(m + n*m) SC-O(n + m) */
}