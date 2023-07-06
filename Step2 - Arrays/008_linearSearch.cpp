#include <bits/stdc++.h>
using namespace std;

/* method 1 (apply linear search) */
int linearSearch(vector<int> &arr, int n, int target)
{
    // apply linear search
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i; // found target

    // if we not found target
    return -1;
    /*  TC-O(n)
        SC-O(1) */
}