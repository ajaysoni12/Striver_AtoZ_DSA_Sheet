#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0, second = 0;
    while (first < s1.size())
    {
        if (second < s2.size() && s1[first] == s2[second])
            first++, second++;
        else
            first++;
    }
    if (first == s1.size() && second == s2.size())
        return true;
    return false;
}
bool cmp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
int longestStringChain(vector<string> &arr)
{
    // subset not subseqeunce
    sort(arr.begin(), arr.end(), cmp);

    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
            maxi = dp[i]; 
    }
    return maxi;
    /*  tc-o(n*logn + n*n*len) SC-O(n) */
}