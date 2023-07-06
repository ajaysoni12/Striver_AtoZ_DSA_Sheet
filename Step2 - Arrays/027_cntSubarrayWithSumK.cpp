#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all sub-array) */
int cntSubWithSumK(vector<int> &nums, int n, int k)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int r = i; r <= r; k++)
                sum += nums[r];

            if (sum == k)
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n*n = n^3 - near about)
        SC-O(1) */
}

/* method 2 (better approach: generate all sub-array - maintain running sub) */
int cntSubWithSumK(vector<int> &nums, int n, int k)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 3 (optimal approach: using prefix sum and hashing) */
int cntSubWithSumK(int nums[], int n, int k)
{
    // because of we need to find preSum-k exists or not
    unordered_map<int, int> mp;
    mp[0] = 1; // intially we get subarray, so we need to check sum-k so remove will be 0, that's why we need to put 0 with cnt1
    int cnt = 0, preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += nums[i];       // just cnt preSum
        int remove = preSum - k; // find removed part
        cnt += mp[remove];       // if remove part exists just add up cnt
        mp[preSum] += 1;         // and also put currsum
    }
    return cnt;
    /*  TC-O(n)
        SC-O(n - worse case - O(n^2) ) */
}

int findSubArraySum(int Arr[], int N, int k)
{
    return cntSubWithSumK(Arr, N, k);
}