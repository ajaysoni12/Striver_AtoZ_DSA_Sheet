#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all substring) */
bool isPalin(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}
string lps(string &str, int n)
{
    /*  steps:
        1) produce all substring
        2) check if substring is palindrome
    */

    string longestSubstr = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalin(str, i, j) == true and (j - i + 1) > longestSubstr.size())
                longestSubstr = str.substr(i, j + 1);
        }
    }
    return longestSubstr;
    /*  TC-O(n*n * n = n^3)
        SC-O(1) */
}

/* method 2 (dynamic programming) */

/*  method 3 (optimize approach: extend from center) 
    TC-O(n^2) 
    SC-O(n) */
int expandFromCenter(string str, int i, int j)
{
    while (i >= 0 && j < str.size() && str[i] == str[j])
        i--, j++;

    return j - i - 1;
}
string longestPalin(string s)
{
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // odd or even length, eg: baab or bab
        int len1 = expandFromCenter(s, i, i + 1);
        int len2 = expandFromCenter(s, i, i);

        int len = max(len1, len2);

        if (end - start < len)
        {
            start = i - (len - 1) / 2; // aba
            end = i + len / 2;
        }
    }
    return s.substr(start, end + 1);
    /*  TC-O(n * n = n^2)
        SC-O(1) */
}