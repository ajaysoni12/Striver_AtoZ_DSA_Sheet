#include <bits/stdc++.h>
using namespace std;

void minCoins(int v)
{
    // 5+10 < 20
    // 1, 5, 6, 9, v = 11, then greedy failed
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        // find denomination
        while (v >= deno[i])
        {
            v -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    /*  TC-O(v - not extacly)
        SC-O(1) */
}