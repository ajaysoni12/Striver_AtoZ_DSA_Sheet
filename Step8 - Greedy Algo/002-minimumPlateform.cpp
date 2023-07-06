#include <bits/stdc++.h>
using namespace std;

int findPlateform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= arr[j])
        {
            plat_needed++;
            i++;
        }
        else if (arr[i] > arr[j])
        {
            plat_needed--;
            j++;
        }

        if (plat_needed > result)
            result = plat_needed;
    }

    return result;
    /*  TC-O(2nLogn + 2n)
        SC-O(1 or n(merge sort)) */
}