#include <bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, int sum, vector<int> &arr, int n, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return; 
    }

    // take
    ds.push_back(arr[ind]); // add in your ds
    sum += arr[ind];
    printF(ind + 1, ds, sum, arr, n, k);
    ds.pop_back(); // when we back i need to remove addup value and sum
    sum -= arr[ind];

    // notTake
    printF(ind + 1, ds, sum, arr, n, k);
    /*  TC-O(2^n * n-near about
        2^n-every ind have two option & n for print ds value(not exactly))
        SC-O(n - depth of tree) */
}