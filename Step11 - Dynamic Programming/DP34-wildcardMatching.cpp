#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, string &pattern, string &text)
{
    // base case
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int ll = 0; ll <= i; ll++)
            if (pattern[ll] != '*')
                return false;
        return true;
    }

    if (pattern[i] == text[j] || pattern[i] == '?')
        return f1(i - 1, j - 1, pattern, text);
    if (pattern[i] == '*')
        return f1(i - 1, j, pattern, text) | f1(i, j - 1, pattern, text);
    return false;
    /*  TC-O(expo) SC-O(n + m) */
}
int wildcardMatching(string &pattern, string &text)
{
    int n = pattern.size();
    int m = text.size();
    return f1(n - 1, m - 1, pattern, text);
}

/* memoization */
int f2(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int ll = 0; ll <= i; ll++)
            if (pattern[ll] != '*')
                return false;
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i] == text[j] || pattern[i] == '?')
        return dp[i][j] = f2(i - 1, j - 1, pattern, text, dp);
    if (pattern[i] == '*')
        return dp[i][j] = f2(i - 1, j, pattern, text, dp) | f2(i, j - 1, pattern, text, dp);
    return dp[i][j] = false;
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int wildcardMatching(string &pattern, string &text)
{
    int n = pattern.size();
    int m = text.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, pattern, text, dp);
}

/* 1 - based indexing */
int f2(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j > 0)
        return false;
    if (j == 0 && i > 0)
    {
        for (int ll = 1; ll <= i; ll++)
            if (pattern[ll - 1] != '*')
                return false;
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        return dp[i][j] = f2(i - 1, j - 1, pattern, text, dp);
    if (pattern[i - 1] == '*')
        return dp[i][j] = f2(i - 1, j, pattern, text, dp) | f2(i, j - 1, pattern, text, dp);
    return dp[i][j] = false;
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int wildcardMatching(string &pattern, string &text)
{
    int n = pattern.size();
    int m = text.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, pattern, text, dp);
}

/* tabulation */
int wildcardMatching(string &pattern, string &text)
{
    int n = pattern.size();
    int m = text.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // base case
    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int ll = 1; ll <= i; ll++)
        {
            if (pattern[ll - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
    /*  TC-O(n*m) SC-O(n*m) */
}

/* space optimization */
int wildcardMatching(string &pattern, string &text)
{
    int n = pattern.size();
    int m = text.size();

    vector<bool> prev(m + 1, 0), curr(m + 1, 0);

    // base case
    prev[0] = true;

    for (int j = 1; j <= m; j++)
        prev[j] = false;

    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int ll = 1; ll <= i; ll++)
        {
            if (pattern[ll - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        // for every row, you will assigned with columns value
        curr[0] = flag;

        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (pattern[i - 1] == '*')
                curr[j] = prev[j] | curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr; 
    }

    return prev[m];
    /*  TC-O(n*m) SC-O(n+m) */
}
