#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &ds, vector<int> &nums, set<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.insert(ds);
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            f(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> uniquePerms(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    set<vector<int>> set;
    int freq[arr.size()] = {0};
    for (int i = 0; i < arr.size(); ++i)
        freq[i] = 0;

    f(ds, arr, set, freq);
    for (auto it : set)
        ans.push_back(it);
    return ans;
    /*  TC-O(nLogn + n + n! * nLogn + n*n)
        SC-O(n!) */
}