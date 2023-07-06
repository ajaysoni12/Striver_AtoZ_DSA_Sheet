#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all pairs) */
int reversePair(vector<int> &arr, int n)
{
    int cnt = 0;

    // check for every index
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // condition: "i < j and arr[i] > 2 * arr[j]"
            if (arr[i] > 2 * arr[j])
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 2 (optimize solution: using merge-sorting algo)*/
void merge(vector<int> &arr, int low, int mid, int high)
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
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0; 
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high and arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt; 
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt; 
}
int reversePair(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
    /*  TC-O(2*n*Log(n))
        SC-O(n) */
}