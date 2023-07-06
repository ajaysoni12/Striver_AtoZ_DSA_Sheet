#include <bits/stdc++.h>
using namespace std;
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

int lps(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}