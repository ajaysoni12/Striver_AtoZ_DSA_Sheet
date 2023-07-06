#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);  // o(n) operation

    // try every option
    for (int i = ind; i < arr.size(); i++)
    {
        // remove duplicacy, i != ind means first time no need to compare
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        ds.push_back(arr[i]);
        f(ind + 1, arr, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetSum2(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    f(0, arr, ds, ans);
    return ans;
    /*  TC-O(2^n(total subset)*k(inserting time) + nLog(n))
        SC-O(2^n(total subset) * k(avarage range) + n(defth of recursion)) */
}