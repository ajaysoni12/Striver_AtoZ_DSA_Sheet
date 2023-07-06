#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: character by character match) */
string longCommonPrefix(string arr[], int n)
{
    string ans = "";
    int minLen = INT_MAX;

    // find minimum length string
    for (int i = 0; i < n; i++)
    {
        int len = arr[i].size();
        minLen = min(minLen, len);
    }

    for (int i = 0; i < minLen; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[0][i] != arr[j][i])
            {
                if (ans == "")
                    return "-1";
                return ans;
            }
            ans += arr[0][i];
        }
    }
    return ans;

    /*  TC-O(n*min(shortes string))
        SC-O(1) */
}

/* method 2 (trie data strcture) */