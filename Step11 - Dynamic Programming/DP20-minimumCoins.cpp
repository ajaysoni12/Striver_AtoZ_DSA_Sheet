#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int T, vector<int> &coins)
{
    // base case
    if (ind == 0)
    {
        if (T % coins[0] == 0)
            return T / coins[0];
        else
            return 1e9;
    }

    // try out all possible way
    int notTake = 0 + f1(ind - 1, T, coins);
    int take = INT_MAX;
    if (coins[ind] <= T)
        take = 1 + f1(ind, T - coins[ind], coins);

    return min(notTake, take);
    /*  TC-O(>>2^n) SC-O(>> n) */
}
int minimumCoins(vector<int> &coins, int target)
{
    int n = coins.size();
    return f1(n - 1, target, coins);
}

/* memoization */
int f2(int ind, int T, vector<int> &coins, vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
        if (T % coins[0] == 0)
            return T / coins[0];
        else
            return 1e9;
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    // try out all possible way
    int notTake = 0 + f2(ind - 1, T, coins, dp);
    int take = INT_MAX;
    if (coins[ind] <= T)
        take = 1 + f2(ind, T - coins[ind], coins, dp);

    return dp[ind][T] = min(notTake, take);
    /*  TC-O(n*target) SC-O(n*target + >> n) */
}
int minimumCoins(vector<int> &coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f2(n - 1, target, coins, dp);
}

/* Tabulation */
int minimumCoins(vector<int> &coins, int target)
{
    int n = coins.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    // base case
    for (int T = 0; T <= target; T++)
    {
        if (T % coins[0] == 0)
            prev[T] = T / coins[0];
        else
            prev[T] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if (coins[ind] <= T)
                take = 1 + curr[T - coins[ind]];

            curr[T] = min(notTake, take);
        }   
        prev = curr;
    }

    return prev[target];
    /*  TC-O(n*target) SC-O(target + target) */
}
