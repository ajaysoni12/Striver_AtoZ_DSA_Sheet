#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using sorting) */
bool isAnagram(string &str1, string &str2)
{
    sort(str1.begin(), str2.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2)
        return true;
    return false;
}

/* method 2 (optimize approach: using hashing) */
bool isAnagram(string &str1, string &str2)
{
    int hash[26] = {0};

    // increase freq of str1
    for (auto it : str1)
        hash[it - 'a']++;

    // decrease freq of str2
    for (auto it : str2)
        hash[it - 'a']--;

    for (int i = 0; i < 26; i++)
        if (hash[i] != 0)
            return false;

    return true;
    /*  TC-O(n1 + n2 + 26)
        SC-O(26)*/
}