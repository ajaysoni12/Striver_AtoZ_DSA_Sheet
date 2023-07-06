#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, string &s1, string &s2)
{
    // base case
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    // if it is match, i have two option, either take it or not take it
    if (s1[i] == s2[j])
        return f1(i - 1, j - 1, s1, s2) + f1(i - 1, j, s1, s2);

    // if it is not match, then i have only single option,
    return f1(i - 1, j, s1, s2);
    /*  TC-O(expo-(2^n*2^m)) SC-O(n + m) */
}
int distinctSubsequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    return f1(n - 1, m - 1, s1, s2);
}

/* memoization */
int f2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base case
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // if it is match, i have two option, either take it or not take it
    if (s1[i] == s2[j])
        return dp[i][j] = f2(i - 1, j - 1, s1, s2, dp) + f2(i - 1, j, s1, s2, dp);

    // if it is not match, then i have only single option,
    return dp[i][j] = f2(i - 1, j, s1, s2, dp);
    /*  TC-O(expo-(2^n*2^m)) SC-O(n + m) */
}
int distinctSubsequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, s1, s2, dp);
}

// for tabulation, 1-based indexing recursion
int f3(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // base case
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // if it is match, i have two option, either take it or not take it
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = f2(i - 1, j - 1, s1, s2, dp) + f2(i - 1, j, s1, s2, dp);

    // if it is not match, then i have only single option,
    return dp[i][j] = f2(i - 1, j, s1, s2, dp);
    /*  TC-O(expo-(2^n*2^m)) SC-O(n + m) */
}
int distinctSubsequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, s1, s2, dp);
}

/* tabulation */
int distinctSubsequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // no need of write, because we intialize everything with 0
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    // changing paramter
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if it is match, i have two option, either take it or not take it
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                // if it is not match, then i have only single option,
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][m];
    /*  TC-O(n*m) SC-O(n*m)*/
}

/* space optimization */
int distinctSubsequence(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base case
    prev[0] = curr[0] = 1; 

    // changing paramter
    for (int i = 1; i <= n; i++)
    {
        // run m->1 for furtehre optimization
        for (int j = 1; j <= m; j++)
        {
            // if it is match, i have two option, either take it or not take it
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                // if it is not match, then i have only single option,
                curr[j] = prev[j];
        }
        prev = curr;
    }

    return prev[m];
    /*  TC-O(n*m) SC-O(n*m)*/
}