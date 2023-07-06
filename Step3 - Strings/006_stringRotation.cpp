#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimize approach: using extra space) */
bool stringRotation(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;

    string str3 = str1 + str1;
    int n = str3.length();
    for (int i = 0; i < n; i++)
    {
        if (str3.substr(i, str1.length()) == str2)
            return true;
    }
    return false;
    /*  TC-O(n)
        SC-O(2n) */
}