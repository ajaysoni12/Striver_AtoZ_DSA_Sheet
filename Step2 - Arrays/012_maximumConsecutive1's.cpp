#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimal approach: using linear traverse) */
int maxConsective1s(vector<int> &nums, int n)
{
    // step1 - decclration of some variable
    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // consective 1's
        if (nums[i] == 1)
        {
            cnt++;
            ans = max(ans, cnt);
        }

        // consectiveness is break
        else
            cnt = 0;
    }
    return ans;
    /*  TC-O(n)
        SC-O(1) */
}