#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<int> leftRotateByDTime(vector<int> &arr, int n, int d)
{
    // reduce operation
    d = d % n;

    // stores values, till d position
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];

    // now put value, over right places
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];

    // now put temp array value into last places of arr
    for (int i = n - d; i < n; i++)
        arr[i] = temp[i - (n - d)];

    return arr;
    /* TC-O(d + (n-d) + d) = O(n + d)
       SC-O(d) */
}

/* method 2 (optimal approach: using reverse technique) */
vector<int> leftRotateByDTime(vector<int> &arr, int n, int d)
{
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
    /* TC-O(d + (n-d) + n) = O(n + n) = O(2n) 
       SC-O(1) */
}