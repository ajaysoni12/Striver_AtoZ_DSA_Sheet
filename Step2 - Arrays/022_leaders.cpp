#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute fore approach: using two loops) */
vector<int> leaders(vector<int> &arr, int n)
{
    vector<int> ans;

    // steps1 - try for every index
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }

        // step2 - if leader is still true, means it's my leader
        if (leader == true)
            ans.push_back(arr[i]);
    }

    return ans;
    /*  TC-O(n*n = n^2 - near abouty)
        SC-O(1) */
}

/* method 2 (optimal solution: just keep track of max) */
vector<int> leaders(vector<int> &arr, int n)
{
    // step1 - delcare maxi, who track maximum ele
    int maxi = INT_MIN;
    vector<int> ans;

    // from last to front
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    // formate ask to give from left to right
    reverse(ans.begin(), ans.end());

    // formate ask sorted, so sort the array
    return ans;
    /*  TC-O(n + n = 2n)
        SC-O(1 or n) */
}