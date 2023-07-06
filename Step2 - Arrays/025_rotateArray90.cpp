#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using extra space) */
vector<vector<int>> rotateImageBy90(vector<vector<int>> &arr, int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ans[j][(n - 1) - i] = arr[i][j]; // right side rotation by 90
    }
    return ans;
    /*  TC-O(n*n = n^2)
        SC-O(n*n = n^2)*/
}

/* method 2 (optimal approach: using transpose and reverse) */
vector<vector<int>> rotateImageBy90(vector<vector<int>> &arr, int n)
{
    // step1 - find transpose
    // not go for last row
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);
    }

    // step2 - reverse every row
    // row is arr[i]
    for (int i = 0; i < n; i++)
        reverse(arr[i].begin(), arr[i].end());

    return arr;
    /*  TC-O(n*n/2 + n*n/2-two pointer) 
        SC-O(1) */
}