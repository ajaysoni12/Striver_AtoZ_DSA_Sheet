#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute froce approach: generate all pair) */
int countInversion(vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 2 (better approach: generate all pair) */
int countInversion(vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 2 (optimize solution: using merge sort technique) */
int cnt = 0;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of array
    int right = mid + 1; // starting index of right half of array

    // storing element in temporary array in sorted order
    while (left <= mid and right <= high)
    {
        // if left is smaller or equal to
        if (arr[left] <= arr[high])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // if right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // if element of left half is still left
    while (left <= mid)
        temp.push_back(arr[left++]);

    // if element of right half is stll left
    while (right <= high)
        temp.push_back(arr[right++]);

    // transforming all ele from temp to arr
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
int countInversion(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
    /*  TC-O(n*Log(n))
        SC-O(n-extra array) */
}