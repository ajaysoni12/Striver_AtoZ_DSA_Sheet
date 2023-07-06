#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach 1: using three loops) */
int longestSubarrayWithSumK(vector<int> &arr, int n, int k)
{
    int longestLen = 0; // longest length

    // step1 - start from every index
    for (int i = 0; i < n; i++)
    {
        // step2 - start from i'th place to end of the array
        for (int j = i; j < n; j++)
        {
            // step3 - find sum between i to jth index
            int curr_sum = 0;
            for (int k = i; k <= j; k++)
                curr_sum += arr[k];

            // if sum is equalivent to given k, then update longestLen with max
            if (curr_sum == k)
                longestLen = max(longestLen, j - i + 1);
        }
    }
    return longestLen;
    /*  TC-O(n*n*n = n^3(near about))
        SC-O(1) */
}

/* method 2 (brute froce approach 2: using two loops) */
int longestSubarrayWithSumK(vector<int> &arr, int n, int k)
{
    int longestLen = 0; // longest length

    // step1 - start from every index
    for (int i = 0; i < n; i++)
    {
        // step2 - start from i'th place to end of the array
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            // if sum is equalivent to given k, then update longestLen with max
            if (curr_sum == k)
                longestLen = max(longestLen, j - i + 1);
        }
    }
    return longestLen;
    /*  TC-O(n*n = n^2(near about))
        SC-O(1) */
}

/* method 2 (better solution: for only positive, but both neg & pos i'ts optimal approach: using hashing) */
int longestSubarrayWithSumK(vector<int> &arr, int n, int k)
{
    // find prev sum
    unordered_map<int, int> mp;

    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // if sum is equal to k,
        if (sum == k)
            maxLen = max(maxLen, i + 1);

        // remaining sum will be sum-k
        int rem = sum - k;

        // if it's is find, means k sum subarray exists
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }

        // eg: 2, 0, 0, 3, we need longest subarray
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxLen;
    /*  TC-O(n - if not collison there, otherwise it's n^2 - if lots of colliosn are present)
        SC-O(n) */
}

/* method 3 (optimal approach: using two pointer approach - only for positive element) */
int longestSubarrayWithSumK(vector<int> &arr, int n, int k)
{
    // step1 - intially it's will point starting of array
    int left = 0, right = 0;

    // step2 - intial sum
    int sum = arr[0];
    int maxLen = 0;

    // setp3 - goes till right not cross n
    while (right < n)
    {
        // step4 - if sum is exceed k, the reduce sum with incerase left pointer
        while (left <= right and sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // setp5 - if any case sum is equal to k
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);

        // step6 - sum is lesser than k, then increase right pointer
        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
    /*  TC-O(n(overall right pointer move) + n(overall left pointer move)) = 2n)
        SC-O(1) */
}