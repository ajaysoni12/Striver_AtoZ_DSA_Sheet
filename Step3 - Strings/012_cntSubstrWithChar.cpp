#include <bits/stdc++.h>
using namespace std;

/*  method 1 (brute force approach: generate all substring then cnt) 
    TC - O(n*n*n = n^3-near about)
    SC - O(n) */

/* method 2 (optimize approach: using sliding window approach) */
long long int solve(string &str, int n, int k)
{
    // intially windows size
    int i = 0, j = 0;
    long long int ans = 0;
    long long int dist = 0;

    int hash_cnt[26] = {0};

    while (j < n)
    {
        hash_cnt[str[j] - 'a']++;
        if (hash_cnt[str[j] - 'a'] == 1)
            dist++;

        // decrease the size of window
        while (dist > k)
        {
            hash_cnt[str[i] - 'a']--;
            if (hash_cnt[str[i] - 'a'] == 0)
                dist--;

            i++;
        }

        ans += j - i + 1;
        j++;
    }
    return ans;
}
long long int substrCount(string str, int k)
{
    int n = str.size();
    return solve(str, n, k) - solve(str, n, k - 1);
    /*  TC-O(n + n + n +n = 4n) 
        SC-O(26) */
}