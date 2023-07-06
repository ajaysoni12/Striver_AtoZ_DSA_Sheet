#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using set data structure) */
vector<int> unionOfArray(vector<int> &a, int n1, vector<int> &b, int n2)
{
    // step1 - use set, for storing unique element
    set<int> set;
    for (int i = 0; i < n1; i++)
        set.insert(a[i]);
    for (int i = 0; i < n2; i++)
        set.insert(b[i]);

    // step2 - store all unique element
    vector<int> temp;
    for (auto it : set)
        temp.push_back(it);

    return temp;
    /*  TC-O(n1Log(n) + n2Log(n) + (n1 + n2))
        SC-O(n1 + n2 + (n1 + n2 - storing ans)) */
}

/* method 2 (optimal approach: using two pointer approach) */
vector<int> unionOfArray(vector<int> &a, int n1, vector<int> &b, int n2)
{
    // step1 - declare two pointer
    int i = 0, j = 0;
    vector<int> unionArr; // store all unique element

    // step2 - keep moving
    // till both of pointer not exhausted
    while (i < n1 && j < n2)
    {
        // if first ele is smaller than equal to second ele
        if (a[i] <= b[j])
        {
            // if unionArr empty or back ele is not equal to, then inserted
            if (unionArr.size() == 0 or unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
        }
        else
        {
            // if unionArr empty or back ele is not equal to, then inserted
            if (unionArr.size() == 0 or unionArr.back() != b[j])
                unionArr.push_back(b[j]);
            j++;
        }
    }

    // step3 - if one of the array exhausted
    while (j < n2)
    {
        if (unionArr.size() == 0 or unionArr.back() != b[j])
            unionArr.push_back(b[j]);
        j++;
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 or unionArr.back() != a[i])
            unionArr.push_back(a[i]);
        i++;
    }

    return unionArr;
    /*  TC-O(n1 + n2) because we only move single time
        SC-O(n1 + n2) wrost case - for solve the problem
        otherwise it is O(1) */
}