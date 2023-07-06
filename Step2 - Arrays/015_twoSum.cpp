#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force appraoch: using two loops) */
pair<int, int> twoSum(vector<int> &arr, int n, int target)
{
    // step1 - for every index, find other ele(pair)
    for (int i = 0; i < n; i++)
    {
        // we can start from i+1, because we check for 2, 6 and 6, 2 both are same
        for (int j = 0; j < n; j++)
        {
            // not count same index
            if (i == j)
                continue;

            if (arr[i] + arr[j] == target)
                return {i, j}; // or return true/yes
        }
    }
    return {-1, -1}; // or return false/no
    /*  TC-O(n*n = n^2)
        SC-O(1) */
}

/* method 2 (better solution: using hashing) */
pair<int, int> twoSum(vector<int> &arr, int n, int target)
{
    // step1 - declare map
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int req = target - curr;

        // pair found
        if (mp.find(req) != mp.end())
            return {mp[req], i};

        // othewise keep put curr value, and index
        mp[curr] = i;
    }
    return {-1, -1};
    /*  TC-O(n - if collison not occur)
        SC-O(n) */
}

/* method 3 (optimal appraoch: for variety 1 problem, using two pointer) */
string twoSumm(vector<int> &arr, int n, int target)
{
    // step1 - sort the array
    sort(arr.begin(), arr.end());

    // step2 - two pointer appraoch
    int low = 0, high = n - 1;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == target)
            return "YES";
        else if (sum < target)
            low++;
        else
            high--;
    }
    return "NO";
    /*  TC-O(n*Log(n) + n)
        SC-O(1) */
}