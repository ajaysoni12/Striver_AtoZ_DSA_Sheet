#include <bits/stdc++.h>
using namespace std;

int *lds(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastInd = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (dp[i] % dp[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastInd = i;
        }
    }

    int list[maxi];
    list[0] = arr[lastInd];

    int ind = 1;
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        list[ind++] = arr[lastInd];
    }

    reverse(list, list + maxi);
    return list;
}