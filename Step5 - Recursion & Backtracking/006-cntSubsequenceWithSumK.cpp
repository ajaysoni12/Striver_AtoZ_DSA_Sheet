#include <bits/stdc++.h>
using namespace std;

int printF(int ind, int sum, vector<int> &arr, int n, int k)
{
    if (ind == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }

    // take case
    sum += arr[ind];
    int leftRec = printF(ind + 1, sum, arr, n, k);
    sum -= arr[ind];

    // notTake case
    int rightRec = printF(ind + 1, sum, arr, n, k);

    return leftRec + rightRec;
    /*  TC-O(2^n * n-near about(worst case)
       2^n-every ind have two option & n for print ds value(not exactly))
       SC-O(n - depth of tree) */
}