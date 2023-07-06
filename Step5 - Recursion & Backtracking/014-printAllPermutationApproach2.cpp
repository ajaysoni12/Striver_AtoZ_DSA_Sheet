#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> &arr, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        f(ind + 1, arr, ans);
        swap(arr[ind], arr[i]);
    }
}
vector<vector<int>> printAllPermu(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    f(0, arr, ans);
    return ans;
    /*  TC-O(n!*n)
        SC-O(n! + n) */
}