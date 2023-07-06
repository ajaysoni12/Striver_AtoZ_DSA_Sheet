#include <bits/stdc++.h>
using namespace std;

/* method 1 (otpimize approach: using extra string)*/
string reverseWords(string str)
{
    int n = str.size();
    string ans = "";
    string temp = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '.')
        {
            temp = '.' + temp;
            ans = temp + ans;
            temp = "";
            continue;
        }
        temp += str[i];
    }
    ans = temp + ans;
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}