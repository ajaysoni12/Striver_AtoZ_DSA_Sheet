#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using hashing) */
bool isomorphicString(string &str1, string &str2)
{
    // if length is not equal
    if (str1.length() != str2.length())
        return 0;

    int n = str1.length();
    unordered_map<char, char> m1;
    unordered_map<char, char> m2;
    
    int i;
    for (i = 0; i < n; i++)
    {
        // if both char not present
        if (m1[str1[i]] == 0 && m2[str2[i]] == 0)
        {
            // map
            m1[str1[i]] = str2[i];
            m2[str2[i]] = str1[i];
        }

        // check it's match or not
        if (m1[str1[i]] != str2[i] || m2[str2[i]] != str1[i])
            return 0;
    }
    return true;
    /*  TC-O(n)
        SC-O(26+26 = 52) */
}