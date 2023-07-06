#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
bool ls(vector<int> &arr, int tar)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == tar)
            return true;

    return false;
}
int longestConSeq(vector<int> &arr, int n)
{
    // step1 - intial longest conseq is 1
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        // step2 - start from arr[i] and goes till we not get false
        int cnt = 1;
        int x = arr[i];
        while (ls(arr, x + 1) == true)
        {
            x = x + 1; // next consequtive sequence
            cnt++;
        }
    }

    return longest;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 2 (better solution: using sorting) */
int longestConSeq(vector<int> &arr, int n)
{
    // step1 - sort the array
    sort(arr.begin(), arr.end());

    int lastSmaller = INT_MIN; // keep track of last smaller
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        // continue consequtive sequence
        if (arr[i] - 1 == lastSmaller)
        {
            cnt++;
            lastSmaller = arr[i];
        }

        // continuety break, start new sequence
        else if (arr[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = arr[i];
        }

        // keep update
        longest = max(longest, cnt);
    }
    return longest;
    /*  TC-O(n*Log(n) + n)
        SC-O(1 or n) */
}

/* method 3 (otpimal approach1: using extra space) */
int longestConSeq(vector<int> &arr, int n)
{
    int maxSize = 1e5 + 10;
    int temp[maxSize];
    for (int i = 0; i < maxSize; i++)
        temp[i] = -1;
    int maxLength = 0;

    for (int i = 0; i < n; i++)
        temp[arr[i]]++;

    int cnt = 0;
    for (int i = 0; i < maxSize; i++)
    {
        if (temp[i] > -1)
            cnt++;
        else
        {
            maxLength = max(maxLength, cnt);
            cnt = 0;
        }
    }
    return maxLength;
    /*  TC-O(2*maxSize + n)
        SC-O(maxSize) */
}

/* method 4 (optimal approach2: using set data structure) */
int longestConSeq(vector<int> &arr, int n)
{
    int longest = 1;
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
        set.insert(arr[i]);

    for (auto it : set)
    {
        if (set.find(it - 1) == set.end())
        {
            int cnt = 1;
            int x = it;

            while (set.find(x + 1) != set.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
    /*  TC-O(n + 2n)
        SC-O(n) */
}