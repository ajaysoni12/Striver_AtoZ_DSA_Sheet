#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // left to right
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                dp1[i] = 1 + dp1[prev];
        }
    }

    // right to left
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                dp1[i] = 1 + dp1[prev];
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    return maxi;
}