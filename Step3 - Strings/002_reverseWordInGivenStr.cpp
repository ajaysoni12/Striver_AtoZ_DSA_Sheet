#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: reverse individual words) */
string reverseWord(string &str)
{
    // reverse whole string
    reverse(str.begin(), str.end());

    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '.' or i == str.size())
        {
            reverse(str.begin() + j, str.begin() + i);
            j = i + 1;
        }
    }
    return str;
    /*  TC-O(n + n*n = n^2-near about)
        SC-O(1) */
}

/* method 2 (optimize approach: using extra space) */
string reverseWord(string &str)
{
    int n = str.size();
    string ans = "";  // store whole ans
    string temp = ""; // store string seprated by dots

    for (int i = 0; i < n; i++)
    {
        // if word find
        if (str[i] == '.')
        {
            temp += '.' + temp;
            ans += temp + ans;
            temp = "";
        }
        // otherwise just add char to build word
        else
            temp += str[i];
    }

    // add last word
    ans = temp + ans;
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}