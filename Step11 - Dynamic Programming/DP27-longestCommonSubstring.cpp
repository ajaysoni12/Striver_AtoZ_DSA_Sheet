#include <bits/stdc++.h>
using namespace std;

/* memoization */
int f1(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp, int &ans)
{
    if (ind1 < 0 or ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int take = 0;
    if (s1[ind1] == s2[ind2])
        take = 1 + f1(ind1 - 1, ind2 - 1, s1, s2, dp, ans);

    f1(ind1 - 1, ind2, s1, s2, dp, ans);
    f1(ind1, ind2 - 1, s1, s2, dp, ans);

    ans = max(ans, take);
    return dp[ind1][ind2] = take;
}
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // your code here
    int ans = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int res = f1(n - 1, m - 1, s1, s2, dp, ans);
    return ans;
}

/* tabulation */
int longestCommonString(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                len = max(len, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return len;
}

/* space optimization */
int longestCommonString(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // base case
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                len = max(len, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }

    return len;
}