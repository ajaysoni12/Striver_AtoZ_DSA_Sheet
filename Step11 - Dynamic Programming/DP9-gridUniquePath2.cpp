#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i < 0 || j < 0)
        return 0;

    if (i >= 0 && j >= 0 && grid[i][j] == -1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    int up = f(i - 1, j, grid);
    int left = f(i, j - 1, grid);
    return (up + left);
    /*  TC-O(2^(n*m)) SC-O(n*m + pathLength-(n-1 + m-1)) */
}
int gridUniquePath2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    return f(n - 1, m - 1, grid);
}

/* memoization - overlapping problem */
int f2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 || j < 0)
        return 0;

    if (i >= 0 && j >= 0 && grid[i][j] == -1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f2(i - 1, j, grid, dp);
    int left = f2(i, j - 1, grid, dp);
    return dp[i][j] = (up + left);
    /*  TC-O(n*m) SC-O(n*m + pathLength-(n-1 + m-1)) */
}
int gridUniquePath2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, grid, dp);
}

/* Tabulation */
int gridUniquePath2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case, write on inside loop

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // obstacals
            if (grid[i][j] == -1)
                dp[i][j] = 0;

            // base case
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = (up + left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

/* space optimization */
int gridUniquePath2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);

    // base case, write on inside loop

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            // obstacals
            if (grid[i][j] == -1)
                curr[j] = 0;

            // base case
            else if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = (up + left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
    /*  tc-o(n*m) sc-o(n+m)*/
}
