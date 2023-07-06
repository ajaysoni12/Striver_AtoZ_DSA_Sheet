#include <bits/stdc++.h>
using namespace std;

bool printF(int ind, vector<int> &ds, int sum, vector<int> &arr, int n, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // take case
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (printF(ind + 1, ds, sum, arr, n, k) == true)
        return true;
    ds.pop_back();
    sum -= arr[ind];

    // notTake case
    if (printF(ind + 1, ds, sum, arr, n, k) == true)
        return true;

    return false;
    /*  TC-O(2^n * n-near about
       2^n-every ind have two option & n for print ds value(not exactly))
       SC-O(n - depth of tree) */
}