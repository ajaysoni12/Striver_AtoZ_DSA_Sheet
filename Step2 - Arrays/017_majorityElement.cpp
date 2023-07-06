#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
int majorityElement(vector<int> &arr, int n)
{
    // step1 - for every index cnt occurence
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }

        // in any case, cnt greater than n/2 return the value of ith index
        if (cnt > n / 2)
            return arr[i];
    }
    // no one full-fill given condition
    return -1;
    /*  TC-O(n*n = n^2)
        SC-O(1) */
}

/* method 2 (better approach: using hashing) */
int majorityElement(vector<int> &arr, int n)
{
    // step1 - declare map, or unorderd_map & count freq of each element
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // step2 - if any ele freq have greater than n/2 times return value
    for (auto it : mp)
        if (it.second > n / 2)
            return it.first;

    // step3 - if non of the element not full-fill given condition
    return -1;

    /*  TC-O(nLog(n) or (n - un_mp) + n)
        SC-O(n) */
}

/* method 3 (optimal approach: moore voting alogrithm) */
int majorityElement(vector<int> &arr, int n)
{
    // setps of moore voting alogrtihm
    /*
        cnt == 0, take new ele is your majority element
        if ele is equal then increment cnt
        if ele is not equal then decrement cnt

        in last, varify your answer
    */

    int cnt = 0; // cnt give information about which ele is your majority ele
    int ele;     // assume ele contain majority ele

    for (int i = 0; i < n; i++)
    {
        // when cnt is equal to 0, update your majority ele, and cnt = 1
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }

        // if ele is equal to arr[i] increase cnt
        else if (arr[i] == ele)
            cnt++;

        // if ele is not equal then decrease cnt
        else
            cnt--;
    }

    // varified answer
    int temp = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == ele)
            temp++;

    if (temp > n / 2)
        return ele;
    return -1;
    /*  TC-O(n + n = 2n)
        SC-O(1) */
}