#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all subarray) */
int maxProductSubarray(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
                prod *= arr[k];
            maxi = max(maxi, prod);
        }
    }
    return maxi;
    /*  TC-O(n*n*n = n^3-near about)
        SC-O(1)  */
}

/* method 2 (better approach: generate all subarray and maintain sum) */
int maxProductSubarray(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            maxi = max(maxi, prod);
        }
    }
    return maxi;
    /*  TC-O(n*n = n^2-near about)
        SC-O(1)  */
}

/* method 3 (optimize approach1: using observation) */
int maxProductSubarray(vector<int> &arr, int n)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;

    // traverse from left to right
    for (int i = 0; i < n; i++)
    {
        // edge case
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
    /*  TC-O(n)
        SC-O(1) */
}