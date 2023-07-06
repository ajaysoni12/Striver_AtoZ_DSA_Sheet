#include <bits/stdc++.h>
using namespace std;

/* using recursion */
void printF(int ind, vector<int> &ds, vector<int> &arr, int n)
{
    // base case, if we reach last index
    if (ind == n)
    {
        // print sub sequence
        for (auto it : ds)
            cout << it << " ";

        // if we need to print empty sequence also 
        if (ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }

    // notTake
    printF(ind + 1, ds, arr, n);

    // take
    ds.push_back(arr[ind]); // need to addup 
    printF(ind + 1, ds, arr, n);
    ds.pop_back(); // when i was go back or forward the i need to remove element for removing duplicacy

    /*  TC-O(2^n * n - for every ele you have two       options & n time print subsequence - near about)
        SC-O(n - defth of recursion tree) */
}