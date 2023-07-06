#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int i, int j, string &str1, string &str2)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (str1[i] == str2[j])
        return f1(i - 1, j - 1, str1, str2);
    return 1 + min(f1(i - 1, j, str1, str2), min(f1(i, j - 1, str1, str2),
                                                 f1(i - 1, j - 1, str1, str2)));
    /*  TC-O(expo) SC-O(n + m) */
}
int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    return f1(n - 1, m - 1, s1, s2);
}

/* memoziation */
int f2(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = f2(i - 1, j - 1, str1, str2, dp);
    return dp[i][j] = 1 + min(f2(i - 1, j, str1, str2, dp), min(f2(i, j - 1, str1, str2, dp), f2(i - 1, j - 1, str1, str2, dp)));
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, s1, s2, dp);
}

/* 1 - based indexing memoization */
int f3(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // base case
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i - 1] == str2[j - 1])
        return dp[i][j] = f2(i - 1, j - 1, str1, str2, dp);
    return dp[i][j] = 1 + min(f2(i - 1, j, str1, str2, dp), min(f2(i, j - 1, str1, str2, dp), f2(i - 1, j - 1, str1, str2, dp)));
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int editDistance(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, s1, s2, dp);
}

/* tabulation */
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base caes
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1]
                                                                     [j - 1]));
        }
    }

    return dp[n][m];
    /*  TC-O(n*m) SC-O(n*m) */
}

/* space optimization */
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base caes
    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i; // base case
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
        }
        prev = curr;
    }

    return prev[m];
    /*  TC-O(n*m) SC-O(m + m) */
}
