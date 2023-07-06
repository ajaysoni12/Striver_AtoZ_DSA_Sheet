#include <bits/stdc++.h>
using namespace std;

/* using tabulation */
string lcs(string &str1, string &str2)
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

    int len = dp[n][m];
    int index = len - 1;
    string ans;
    for (int i = 0; i < len; i++)
        ans.push_back('$');

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans[index] = str1[i - 1];
            index--;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return ans;
    /* TC-O(n*m) SC-O(n*m + n+m) */
}