#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using extra space) */
vector<int> moveToZeroEnd(vector<int> &arr, int n)
{
    // step - 1, push all non_zero ele into vector
    vector<int> temp;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            temp.push_back(arr[i]);

    // step - 2, now put all non_zero value into arr array
    int nonZero = temp.size();
    for (int i = 0; i < nonZero; i++)
        arr[i] = temp[i];

    // step - 3, now put 0's into remaining place
    for (int i = nonZero; i < n; i++)
        arr[i] = 0;

    return arr;
    // x is equal to nonZero
    /*  TC-O(n + x + (n-x)) = O(2n)
        SC-O(x), wrost case - O(n) */
}

/* method 2 (optimal approach: using two pointer approach) */
vector<int> moveToZeroEnd(vector<int> &arr, int n)
{
    // step 1 - find first zero'th location
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // step 2 - if we not find any zero
    if (j == -1)
        return arr;

    // step 3 - now swap zero'th index value to non_zero'th index value
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
    // x = find first zero'th length
    /*  TC-O(x + (n - x)) = O(n)
        SC-O(1) */
}