#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: part1 contineues) */
void f(int ind, int target, vector<int> &arr, vector<int> &ds, set<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        if (target == 0)
            ans.insert(ds); // k*log(k)
        return;
    }

    // pick element only once
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        f(ind + 1, target - arr[ind], arr, ds, ans);
        ds.pop_back();
    }

    f(ind + 1, target, arr, ds, ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> set;
    vector<int> ds;
    f(0, target, arr, ds, set);
    vector<vector<int>> ans;
    for (auto it : set)
        ans.push_back(it);
    return ans;
    /*  TC-O(2^n * kLogk)
        SC-O(n-depth of rec + nLogn + n + n*nlogn) */
}

/* method 2 (optimize appraoch: ) */
void f(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds); // take o(k) operation
        return;
    }

    // i have couple of option two pic
    for (int i = ind; i < arr.size(); i++)
    {
        // remove duplicacy
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        // if any case curr index value is greater than, then definetely further element is increase
        if (arr[i] > target)
            break;

        // store in ds
        ds.push_back(arr[i]);
        f(i + 1, target - arr[i], arr, ds, ans);
        // remove in ds, back from previous ds
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    // we need in sorted order
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    f(0, target, arr, ds, ans);
    return ans;
    /*  TC-O(if all ele are unique then for total no. of subsequence is 2^n * k)
        SC-O(k * x, k is total subsequence with x length)*/
}