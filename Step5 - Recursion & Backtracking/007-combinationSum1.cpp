#include <bits/stdc++.h>
using namespace std;

void f(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (ind == arr.size())
    {
        if (target == 0)
            ans.push_back(ds); // this is o(k) operation
        return;
    }

    // pick up the element
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        f(ind, target - arr[ind], arr, ds, ans);
        ds.pop_back();
    }

    // not pick up the element
    f(ind + 1, target, arr, ds, ans);
}
vector<vector<int>> combinationSum1(vector<int> &arr, int target)
{
    // sort them 
    sort(arr.begin(), arr.end());
    // remove duplicate element
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    f(0, target, arr, ds, ans);
    return ans;

    /*  TC-O(2^t(multiple time pic same ele)*k(length of ds))
        SC-O(unpretictable or k(length of ans*x(total ans)) */
}