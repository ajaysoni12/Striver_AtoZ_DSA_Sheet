#include <bits/stdc++.h>
using namespace std;

void f(int ind, int sum, vector<int> &arr, int n, vector<int> &subsetSum)
{
    if (ind == n)
    {
        subsetSum.push_back(sum);
        return;
    }

    // pick the element
    f(ind + 1, sum + arr[ind], arr, n, subsetSum);

    // don't pick the element
    f(ind + 1, sum, arr, n, subsetSum);
}
vector<int> subsetSum1(vector<int> &arr, int n)
{
    vector<int> ans;
    f(0, 0, arr, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
    /*  TC-O(2^n(generate all subset/subsequence) + 2^nLog(2^n) -sorting)
        SC-O(2^n) */
}