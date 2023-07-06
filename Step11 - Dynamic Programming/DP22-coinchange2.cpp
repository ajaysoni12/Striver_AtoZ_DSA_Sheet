#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int ind, int T, int *deno)
{
    // base case
    if (ind == 0)
        return (T % deno[ind] == 0); // 0 or 1

    int notTake = f1(ind - 1, T, deno);
    int take = 0;
    if (deno[ind] <= T)
        take = f1(ind, T - deno[ind], deno);

    return notTake + take;
    /*  TC-O(>>2^n-expo) SC-O(>>n or T, assument coins will be {1, 1}) */
}
long long cntWaysToMakechange(int *deno, int n, int target)
{
    return f1(n - 1, target, deno);
}

/* memoization */
int f2(int ind, int T, int *deno, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
        return (T % deno[ind] == 0); // 0 or 1

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTake = f2(ind - 1, T, deno, dp);
    int take = 0;
    if (deno[ind] <= T)
        take = f2(ind, T - deno[ind], deno, dp);

    return dp[ind][T] = notTake + take;
    /*  TC-O(n*target) SC-O(n*target + >>n or T, assument coins will be {1, 1}) */
}
long long cntWaysToMakechange(int *deno, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f2(n - 1, target, deno, dp);
}

/* tabulation */
long long cntWaysToMakechange(int *deno, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int T = 0; T <= target; T++)
        dp[0][T] = (T % deno[0] == 0);

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + dp[ind - 1][T];
            int take = 0;
            if (deno[ind] <= T)
                take = dp[ind][T - deno[ind]];
            dp[ind][T] = notTake + take;
        }
    }

    return dp[n - 1][target];
    /*  TC-O(n*target) SC-O(n*target) */
}

/* space optimization */
long long cntWaysToMakechange(int *deno, int n, int target)
{
    vector<long long> prev(target + 1, 0), curr(target + 1, 0);

    for (int T = 0; T <= target; T++)
        prev[T] = (T % deno[0] == 0);

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + prev[T];
            int take = 0;
            if (deno[ind] <= T)
                take = curr[T - deno[ind]];
            curr[T] = notTake + take;
        }
        prev = curr;
    }

    return prev[target];
    /*  TC-O(n*target) SC-O(2*target) */
}