#include <bits/stdc++.h>
using namespace std;

int lisUsingBinarySearch(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
            temp.push_back(arr[i]);
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    // temp array not a lis
    return temp.size();
    /*  TC-O(n*logn) SC-O(n) */
}