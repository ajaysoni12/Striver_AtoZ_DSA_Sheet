#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using set data structrue) */
vector<int> removeDuplicate(vector<int> &arr, int n)
{
    // for storing unique element, and sorted order
    set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(arr[i]); // log(n)

    // push into starting of arr
    int index = 0;
    for (auto it : set)
        arr[index++] = it;

    return arr;
    /* TC-O(n*log(n) + n) SC-O(n) */
}

/* method 2 (optimal approach: using two pointer approach) */
int removeDuplicate(vector<int> &arr)
{
    int ind = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++)
    {
        if (arr[ind] != arr[j])
        {
            arr[ind + 1] = arr[j];
            ind++;
        }
    }
    return ind + 1;
    /* TC-O(n) SC-O(1) */
}
