#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimal approach) */
vector<int> leftRotateByOne(vector<int> &arr, int n)
{
    // suttle change, first index value goes down into last index, and other elemenet just replace prev one
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];
    arr[n - 1] = temp;
    return arr;
    /* TC-O(n) SC-O(1) */
}