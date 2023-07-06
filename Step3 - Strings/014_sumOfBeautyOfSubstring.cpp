#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimize approach: using hashing) */
int beautySumSubstr(string &str)
{
    int n = str.size();
    int beautySum = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};
        for (int j = i; j < n; j++)
        {
            int low = INT_MAX, high = INT_MIN;
            freq[str[j] - 'a']++;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] != 0)
                {
                    low = min(low, freq[k]);
                    high = max(high, freq[k]);
                }
            }

            beautySum += (high - low);
        }
    }
    return beautySum;
    /*  TC-O(n * n * 26)
        SC-O(1) */
}
