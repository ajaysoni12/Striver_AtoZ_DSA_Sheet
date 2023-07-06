#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> &arr, int n)
{
    int total_sum = 0;
    for (int i = 0; i < n; i++)
        total_sum += arr[i];

    int k = total_sum;

    // vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);

    /*
        // for target equal to
        for (int ind = 0; ind < n; ind++)
            dp[ind][0] = true;
    */
    prev[0] = curr[0] = true; // for target 0, mark true

    /*
        // for ind equal to
        dp[0][arr[0]] = true;
    */

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTake = prev[target];
            int take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];

            curr[target] = notTake | take;
        }
        prev = curr;
    }

    // dp[n - 1][col->0, 1, 2, ......totalSum]
    int mini = 1e9;
    for (int s1 = 0; s1 <= total_sum / 2; s1++)
    {
        if (prev[s1] == true)
            mini = min(mini, abs((total_sum - s1) - s1));
    }

    return mini;
    /*  TC-O(n*k) SC-O(n+k )*/
}