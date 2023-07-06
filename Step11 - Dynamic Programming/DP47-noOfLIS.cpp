#include <bits/stdc++.h>
using namespace std;

int noOfLIS(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            // it's is new subsequence
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }

            // someone same length
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
                cnt[i] += cnt[prev];
        }
        maxi = max(maxi, dp[i]);
    }

    int noOfLIS = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] == maxi)
            noOfLIS += cnt[i];
    }
    return noOfLIS;
    /*  TC-O(n*n) SC-O(n+n)*/
}