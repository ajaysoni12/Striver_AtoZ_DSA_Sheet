#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;      // [low...mid]
    int right = mid + 1; // [right...high]

    // merge two sorted array
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // either left part, lefft or right part, left, just push
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copy into orignal array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void mSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mSort(arr, low, mid);
    mSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void mergeSort(vector<int> &arr, int n)
{
    mSort(arr, 0, n - 1);
    /*  TC-O(n*Log(n)), n-for merge, and every time do n/2 i.e. log2(n) 

                    16 (n)
            8(n/2)         8(n/2)
        4(n/4)                  4(n/4)
        SC-O(n) */
}