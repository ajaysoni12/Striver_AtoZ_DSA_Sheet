#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subset(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> subsets;

    for (int mask = 0; mask < subset_ct; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if ((mask & (1 << i)) != 0)
                subset.push_back(nums[i]);

        subsets.push_back(subset);
    }
    return subsets;
    /*  TC-O(2^n * n)
        SC-O(n) */
}