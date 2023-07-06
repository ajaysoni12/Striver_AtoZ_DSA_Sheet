#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int buy, vector<int> &price, int n)
{
    // base case
    if (ind >= n)
        return 0;

    // buy
    if (buy == 1)
        return max(-price[ind] + f1(ind + 1, 0, price, n),
                   0 + f1(ind + 1, 1, price, n));

    // sell,
    // can not buy right after sell, that why +2
    return max(price[ind] + f1(ind + 2, 1, price, n),
               0 + f1(ind + 1, 0, price, n));

    /*  TC-O(2^n) SC-O(n) */
}
int buySellStock5(vector<int> &prices, int n)
{
    return f1(0, 1, prices, n);
}

/* memoization */
int f2(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
{
    // base case
    if (ind >= n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    // buy
    if (buy == 1)
        return dp[ind][buy] = max(-price[ind] + f2(ind + 1, 0, price, n, dp),
                                  0 + f2(ind + 1, 1, price, n, dp));

    // sell,
    // can not buy right after sell, that why +2
    return dp[ind][buy] = max(price[ind] + f2(ind + 2, 1, price, n, dp),
                              0 + f2(ind + 1, 0, price, n, dp));

    /*  TC-O(n*2) SC-O(n*2 + n) */
}
int buySellStock5(vector<int> &prices, int n)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f2(0, 1, prices, n, dp);
}

/* tabulation */
int buySellStock5(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // no need to write base case

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // buy
            if (buy == 1)
                dp[ind][buy] = max(-price[ind] + dp[ind + 1][0],
                                   0 + dp[ind + 1][1]);

            // sell,
            // can not buy right after sell, that why +2
            else
                dp[ind][buy] = max(price[ind] + dp[ind + 2][1],
                                   0 + dp[ind + 1][0]);
        }
    }

    return dp[0][1];
    /*  TC-O(n*2) SC-O(n*2) */
}

/* for space otpimization, use tree row */
/* you can remove innner loop and use if else */
int buySellStock5(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // no need to write base case

    for (int ind = n - 1; ind >= 0; ind--)
    {
        dp[ind][1] = max(-price[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);

        // sell,
        // can not buy right after sell, that why +2
        dp[ind][0] = max(price[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
    }

    return dp[0][1];
    /*  TC-O(n) SC-O(n*2) */
}