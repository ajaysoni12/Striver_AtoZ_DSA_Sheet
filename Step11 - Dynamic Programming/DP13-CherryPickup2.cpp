#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    // out of bound case
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;

    // base case
    if (i == r - 1)
    {
        // take only one time
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // explore all paths of alic and bob simultaneously
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value += grid[i][j1];
            else
                value += grid[i][j1] + grid[i][j2];

            value += f1(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
    /*  TC-O(3^n*3^n) SC-O(n) */
}
int maxChocolatesCollect(int r, int c, vector<vector<int>> &grid)
{
    return f1(0, 0, c - 1, r, c, grid);
}

/* Memoization */
int f2(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,
       vector<vector<vector<int>>> &dp)
{
    // out of bound case
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;

    // base case
    if (i == r - 1)
    {
        // take only one time
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // explore all paths of alic and bob simultaneously
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value += grid[i][j1];
            else
                value += grid[i][j1] + grid[i][j2];

            value += f2(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
    /*  TC-O(n*m*m*9) SC-O(n) */
}
int maxChocolatesCollect(int r, int c, vector<vector<int>> &grid)
{
    // int dp[r][c][c]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return f2(0, 0, c - 1, r, c, grid, dp);
}

/* Tabulation */
int maxChocolatesCollect(int r, int c, vector<vector<int>> &grid)
{
    // int dp[r][c][c]
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // base case
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j2];
            else
                dp[r - 1][j1][j2] = (grid[r - 1][j1] + grid[r - 1][j2]);
        }
    }

    // try out all ways
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + dj1 >= 0 && j1 + dj1 < c &&
                            j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += (-1e8);
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
    /*  TC-O(m1*m2 + n1*m1*m2*9) SC-O(n1*m1*m2) */
}

/* space otpimization */
int maxChocolatesCollect(int r, int c, vector<vector<int>> &grid)
{
    // int dp[r][c][c], convert into 2-d dp
    vector<vector<int>> next(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));
    // base case
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                next[j1][j2] = grid[r - 1][j2];
            else
                next[j1][j2] = (grid[r - 1][j1] + grid[r - 1][j2]);
        }
    }

    // try out all ways
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + dj1 >= 0 && j1 + dj1 < c &&
                            j2 + dj2 >= 0 && j2 + dj2 < c)
                            value += next[j1 + dj1][j2 + dj2];
                        else
                            value += (-1e8);
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }
    return next[0][c - 1];
    /*  TC-O(m1*m2 + n1*m1*m2*9) SC-O(2*m1*m2) */
}