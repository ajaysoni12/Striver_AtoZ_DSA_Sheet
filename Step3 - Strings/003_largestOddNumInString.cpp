#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimize approach: using observation) */
string largestOddNum(string &str)
{
    for (int i = str.size() - 1; i >= 0; i--)
        if ((str[i] - '0') % 2 != 0)
            return str.substr(0, i + 1);

    return "";
    /*  TC-O(n)
        SC-O(1) */
}

