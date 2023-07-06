#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 && j == 0)
        return grid[i][j];

    // out of bound case
    if (i < 0 || j < 0)
        return 1e9;

    int up = grid[i][j] + f1(i - 1, j, grid);
    int left = grid[i][j] + f1(i, j - 1, grid);
    return min(up, left);
    /*  TC-O(2^(n*m)) SC-O(pathLength - (n-1 + m-1)) */
}
int minPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    return f1(n - 1, m - 1, grid);
}

/* memoization - overlapping subproblem */

int f2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return grid[i][j];

    // out of bound case
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + f2(i - 1, j, grid, dp);
    int left = grid[i][j] + f2(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
    /*  TC-O(n*m) SC-O(pathLength - (n-1 + m-1) + n*m) */
}
int minPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, grid, dp);
}

/* Tabulation(Bottom-up) */
int minPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case, write on loop inside
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
    /*  TC-O(n*m-you will just compute this steps) SC-O(n*m-dp) */
}

/* space optimization */
int minPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);

    // base case, write on loop inside
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;
                if (j > 0)
                    left += curr[j - 1];
                else
                    up += 1e9;
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
    /*  TC-O(n*m-you will just compute this steps) SC-O(n + m) */
}