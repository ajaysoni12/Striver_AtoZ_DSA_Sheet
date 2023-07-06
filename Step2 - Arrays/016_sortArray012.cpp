#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using sorting-merge sort) */
void sort012(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    /*  TC-O(nLog(n))
        SC-O(n-merge sort) */
}

/* method 2 (better approach: cnt 0, 1, & 2's) */
void sort012(vector<int> &arr, int n)
{
    // step1 - cnt 0, 1, 2's
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        if (arr[i] == 1)
            cnt1++;
        if (arr[i] == 2)
            cnt2++;
    }

    // step2 - manually filip 0, 1, and 2's
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;
    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2;

    /*  TC-O(n + (cnt0+cnt1+cnt2 = n) = 2n)
        SC-O(1)  */
}

/* method 3 (optimal approach: dutch national flag alog) */
void sort012(vector<int> &arr, int n)
{
    // basic of dutch national flag alogrithm
    /*
        0 to low-1 will contain 0 (sorted)
        low to mid-1 will contain 1 (sorted)
        mid to high will contain 0, 1, 2 (unsorted)
        high+1 to n-1 will contain 2 (sorted)
    */

    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++, mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    /*  TC-O(n)
        SC-O(1) */
}