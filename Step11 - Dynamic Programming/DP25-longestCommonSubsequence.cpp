#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind1, int ind2, string &str1, string &str2)
{
    // base case
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // if both character match
    if (str1[ind1] == str2[ind2])
        return 1 + f1(ind1 - 1, ind2 - 1, str1, str2);

    // otherwise go one steps back, in both of the string
    return 0 + max(f1(ind1 - 1, ind2, str1, str2), f1(ind1, ind2 - 1, str1, str2));
    /*  TC-O(2^n * 2^m - expo) SC-O(n + m) */
}
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    return f1(n - 1, m - 1, str1, str2);
}

/* memoization */
int f2(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
{
    // base case
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // if both character match
    if (str1[ind1] == str2[ind2])
        return dp[ind1][ind2] = 1 + f2(ind1 - 1, ind2 - 1, str1, str2, dp);

    // otherwise go one steps back, in both of the string
    return dp[ind1][ind2] = 0 + max(f2(ind1 - 1, ind2, str1, str2, dp), f2(ind1, ind2 - 1, str1, str2, dp));
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f2(n - 1, m - 1, str1, str2, dp);
}

/* for tabulation we need to perform index right side
-1, 0, 1, 2, 3, 4
0, 1, 2, 3, 4, 5 */
int f2(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
{
    // base case
    if (ind1 == 0 || ind2 == 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // if both character match
    if (str1[ind1 - 1] == str2[ind2 - 1])
        return dp[ind1][ind2] = 1 + f2(ind1 - 1, ind2 - 1, str1, str2, dp);

    // otherwise go one steps back, in both of the string
    return dp[ind1][ind2] = 0 + max(f2(ind1 - 1, ind2, str1, str2, dp), f2(ind1, ind2 - 1, str1, str2, dp));
    /*  TC-O(n*m) SC-O(n*m + n + m) */
}
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, str1, str2, dp);
}

/* tabulation */
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
    /* TC-O(n*m) SC-O(n*m) */
}

/* space optimization */
int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base case
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr; 
    }

    return prev[m];
    /* TC-O(n*m) SC-O(m + m) */
}
