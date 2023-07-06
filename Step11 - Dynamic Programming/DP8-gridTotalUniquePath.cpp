#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int i, int j, vector<vector<int>> &grid, int n, int m)
{
    // base case
    // 1. we reach
    if (i == 0 && j == 0)
        return 1;
    // 2. out of bound
    if (i < 0 || j < 0)
        return 0;

    // down or up
    int up = f1(i - 1, j, grid, n, m);

    // right or left
    int left = f1(i, j - 1, grid, n, m);

    // total ways
    return up + left;
    /*  TC-O(2^(n*m)) SC-O(path length - (n-1 + m-1))*/
}
int gridUniquePath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.size();
    return f1(n - 1, m - 1, grid, n, m);
}

/* Memozation */
int f2(int i, int j, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp)
{
    // base case
    // 1. we reach
    if (i == 0 && j == 0)
        return 1;
    // 2. out of bound
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // down or up
    int up = f2(i - 1, j, grid, n, m, dp);

    // right or left
    int left = f2(i, j - 1, grid, n, m, dp);

    // total ways
    return dp[i][j] = up + left;
    /*  TC-O(n*m-no.of rec calls) SC-O(path length - (n-1 + m-1-rec) + n*m)*/
}
int gridUniquePath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, grid, n, m, dp);
}

/* Tabulation */
int gridUniquePath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case
    dp[0][0] = 1;

    // changing parameter
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
    /*  TC-O(n*m) SC-O(n*m) */
}

/* space optimization */
int gridUniquePath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.size();

    vector<int> prev(m, 0);

    // changing parameter
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
    /*  TC-O(n*m) SC-O(n+m) */
}
