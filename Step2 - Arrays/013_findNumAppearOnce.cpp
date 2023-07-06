#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
int findNumAppearOne(vector<int> &nums, int n)
{
    // for every ele
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int cnt = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == num)
                cnt++;
        }

        // if cnt is 1, means it's present only once time
        if (cnt == 1)
            return num;
    }
    /*  TC-O(n*n = n^2)
        SC-O(1) */
}

/* method 2 (better approach: using hashing) */
int findNumAppearOne(vector<int> &nums, int n)
{
    // step1 - find freq of ele
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    // step2 - which ele have 1 freq
    for (auto it : mp)
        if (it.second == 1)
            return it.first;

    return -1;
    /*  TC-O(n-bestcase, worstcase-n^2 - use map + (n/2+1 - half ele we store in map)
        SC-O(n/2+1)) */
}

/* method 3 (optimal approach: using xor property) */
int findNumAppearOne(vector<int> &nums, int n)
{
    // xor property
    // if we do same number xor we get 0
    // if we do xor with 0 we get num
    int _xor = 0;
    for (int i = 0; i < n; i++)
        _xor ^= nums[i];

    return _xor;
    /*  TC-O(n)
        SC-O(1) */
}