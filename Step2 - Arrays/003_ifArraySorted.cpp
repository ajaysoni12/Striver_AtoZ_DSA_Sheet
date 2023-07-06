#include <bits/stdc++.h>
using namespace std;

/* method 1 (Optimal Approach) */
bool ifArraySorted(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
    /* TC-O(n) SC-O(1) */
}