#include <bits/stdc++.h>
using namespace std;

int maxSumFromAdjEle(vector<int> &arr)
{
    int n = arr.size(); 

    // base case
    int prev2 = 0;
    int prev1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int notTake = 0 + prev1;
        int curri = max(take, notTake);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
    /*  TC-O(n) SC-O(1) */
}

// circular adjacent
long long houseRobber(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(arr[i]);
        if (i != n - 1)
            temp2.push_back(arr[i]);
    }

    return max(maxSumFromAdjEle(temp1), maxSumFromAdjEle(temp2));
}