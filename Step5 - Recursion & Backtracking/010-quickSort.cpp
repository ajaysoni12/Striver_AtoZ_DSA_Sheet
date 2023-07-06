#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i <= high - 1 && arr[i] <= pivot)
            i++;
        while (j >= low + 1 && arr[j] >= pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qsort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qsort(arr, low, pIndex - 1);
        qsort(arr, pIndex + 1, high);
    }
}
vector<int> quickSort(vector<int> &arr, int n)
{
    qsort(arr, 0, n - 1);
    return arr;
    /*  TC-O(n(partition)*Logn(dividing)) 
        SC-O(1 or n) */
}