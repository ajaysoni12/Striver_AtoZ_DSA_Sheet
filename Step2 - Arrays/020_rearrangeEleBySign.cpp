#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using extra space) */
vector<int> rearrangeEleBySign(vector<int> &arr, int n)
{
    vector<int> pos, neg; // store pos, neg ele
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = pos[i];     // even index, put pos ele
        arr[2 * i + 1] = neg[i]; // odd index, put neg ele
    }
    return arr;
    /*  TC-O(n + n/2)
        SC-O(n/2 + n/2) */
}

/* method 2 (optimal approach: using linear traverse) */
vector<int> rearrangeEleBySign(vector<int> &arr, int n)
{
    vector<int> ans(n);
    int pos = 0, neg = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans[neg] = arr[i];
            neg += 2;
        }
        else
        {
            ans[pos] = arr[i];
            pos += 2;
        }
    }
    return ans;
    /*  TC-O(n)
        SC-O(1) */
}

/* method 3 (if neg != pos)*/
void rearrange(int arr[], int n)
{
    vector<int> neg, pos;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int ind1 = 0, ind2 = 0;
    int index = 0;
    while (ind1 < neg.size() and ind2 < pos.size())
    {
        arr[index++] = pos[ind2++];
        arr[index++] = neg[ind1++];
    }

    while (ind1 < neg.size())
        arr[index++] = neg[ind1++];
    while (ind2 < pos.size())
        arr[index++] = pos[ind2++];
}