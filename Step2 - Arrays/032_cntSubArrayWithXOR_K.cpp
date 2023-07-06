#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all sub-array) */
int cntSubarrayWithXORK(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int _xor = 0;
            for (int k = i; k <= j; k++)
                _xor ^= arr[k];

            // if _xor subarray value is equal to k, then increase cnt
            if (_xor == k)
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n*n = n^3-near about)
        SC-O(1) */
}

/* method 2 (better approach: maintain running sum) */
int cntSubarrayWithXORK(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int _xor = 0;
        for (int j = i; j < n; j++)
        {
            _xor ^= arr[k];
            // if _xor subarray value is equal to k, then increase cnt
            if (_xor == k)
                cnt++;
        }
    }
    return cnt;
    /*  TC-O(n*n = n^2-near about)
        SC-O(1) */
}

/* method 3 (optimal approach: ) */
int cntSubarrayWithXORK(vector<int> &arr, int n, int k)
{
    /*
        Algo: 
            first find total subarray with xor 
            then remove k, and find x value 
            if x value present that means defenitely subarray will be present
    */



    int xr = 0; // total xor till ith position
    unordered_map<int, int> mp;
    mp[xr]++; // {0, 1}
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        // need x = xr^k
        int x = xr ^ k;
        cnt += mp[x];   
        mp[xr]++;
    }
    return cnt;
    /*  TC-O(n or nLog(n)) 
        SC-O(n) */
}