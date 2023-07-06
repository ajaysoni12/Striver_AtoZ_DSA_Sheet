#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approch: generate all triplets) */
vector<vector<int>> triplets(vector<int> &nums, int n)
{
    // for storing unique ele
    set<vector<int>> set;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // for removing duplicacy
                    set.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(set.begin(), set.end());
    return ans;
    /*  TC-O(n*n*n*log(unique)) = n^3 * Log(uniqueEle)))
        SC-O(2*noOf triplets) */
}

/* method 2 (better solution: using hashing) */
vector<vector<int>> triplets(vector<int> &nums, int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end()); // for removing duplicacy
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    /*  TC-O(n*n*log(unique)) = n^2 * Log(uniqueEle)))
        SC-O(n) + O(noOfUnique*2) */
}