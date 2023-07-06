#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int i, int j, vector<vector<int>> &triangle, int n, int m)
{
    // base case
    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + f1(i + 1, j, triangle, n, m);
    int diagonal = triangle[i][j] + f1(i + 1, j + 1, triangle, n, m);
    return min(down, diagonal);
    /*  TC-O(col-1+2+3+4+5, and each i,j have two option
    2^(sum of n)) SC-O(n) */
}
int triangleMinPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    return f1(0, 0, triangle, n, m);
}

/* memoization - sub overlapping problem */
int f2(int i, int j, vector<vector<int>> &triangle, int n,
       vector<vector<int>> &dp)
{
    // base case
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + f2(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + f2(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = min(down, diagonal);
    /*  TC-O(col-1+2+3+4+5, and each i,j have two option
    2^(sum of n)) SC-O(n) */
}
int triangleMinPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f2(0, 0, triangle, n, dp);
}

/* Tabulation */
int triangleMinPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case or you can write inside loop also
    // for (int j = 0; j < n; j++)
    //     dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            if (i == n - 1)
                dp[i][j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
    }

    return dp[0][0];
    /*  TC-O(1+2+3+4+5..n - each row, col size) SC-O(n*m) */
}

/* space optimization */
int triangleMinPathSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    vector<int> next(n, 0);

    // base case or you can write inside loop also
    // for (int j = 0; j < n; j++)
    //     curr[j] = triangle[n - 1][j];

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            if (i == n - 1)
                curr[j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j + 1];
                curr[j] = min(down, diagonal);
            }
        }
        next = curr;
    }

    return next[0];
    /*  TC-O(1+2+3+4+5..n - each row, col size) SC-O(n+m) */
}
