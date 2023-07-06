#include <bits/stdc++.h>
using namespace std;

/*  method 1 (brute force appraoch: using extra space) */
void mergeArray(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> mergeArr(n + m);
    int left = 0, right = 0;
    int ind = 0;

    // combine into single array, but ele is sorted
    while (left < n and right < m)
    {
        if (arr1[left] <= arr2[right])
            mergeArr[ind++] = arr1[left++];
        else
            mergeArr[ind++] = arr2[right++];
    }

    // if one can exhausted
    while (left < n)
        mergeArr[ind++] = arr1[left++];
    while (right < m)
        mergeArr[ind++] = arr1[right++];

    // now, push again
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            arr1[i] = mergeArr[i];
        else
            arr2[i - n] = mergeArr[i];
    }
    /*  TC-O(n+m - for push into array + n+m - for again push into array)
        SC-O(n + m - extra array) */
}

/*  method 2 (better solution: using two pointer technique) */
void mergeArray(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // start from last
    int left = n - 1;
    int right = 0;

    while (left >= 0 and right < m)
    {
        // if condition satiesfied then swap
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
            break; // if it is sorted, no need to check for other ele
    }

    // need to sorted
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    /*  TC-O(min(n, m) + nLog(n) + mLog(m))
        SC-O(1) */
}

/*  method 3 (optimized solution: using gap(shell sort) method) */
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
        swap(arr1[ind1], arr2[ind2]);
}
void mergeArray(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int len = (n + m);
    int gap = (len / 2) + (len % 2); // ceil value

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // arr1 and arr2 compare
            if (left < n and right >= n)
            {
                // right - n because of it's on second array
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2, if left is second part then definetly right also on second part
            else if (left >= n)
            {
                // -n because of both of the on second array
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                // not need of doing -n
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
    /*  TC-O(Log2(n+m)-whenever divide by two * O(n+m)-near about)
        SC-O(1) */
}
