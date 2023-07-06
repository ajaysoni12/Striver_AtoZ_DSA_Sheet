#include <bits/stdc++.h>
using namespace std;

/* recursion */
long f1(int ind, int buy, long *val, int n, int tsFee)
{
    // base case
    if (ind == n)
        return 0;

    long profit = 0;
    if (buy)
    {
        profit = max(-val[ind] + f1(ind + 1, 0, val, n, tsFee),
                     0 + f1(ind + 1, 1, val, n, tsFee));
    }
    else
    {
        profit = max(val[ind] - tsFee + f1(ind + 1, 1, val, n, tsFee),
                     0 + f1(ind + 1, 0, val, n, tsFee));
    }
    return profit;
    /*  TC-O(2^n) SC-O(n) */
}
long buySellStocks2(long *val, int n, int tsFee)
{
    // {start, buy}
    return f1(0, 1, val, n, tsFee);
}

/* memoization */
long f2(int ind, int buy, long *val, int n, vector<vector<int>> &dp, int tsFee)
{
    // base case
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;
    if (buy)
    {
        profit = max(-val[ind] + f2(ind + 1, 0, val, n, dp, tsFee),
                     0 + f2(ind + 1, 1, val, n, dp, tsFee));
    }
    else
    {
        profit = max(val[ind] - tsFee + f2(ind + 1, 1, val, n, dp, tsFee),
                     0 + f2(ind + 1, 0, val, n, dp, tsFee));
    }
    return dp[ind][buy] = profit;
    /*  TC-O(n*2) SC-O(n*2 + n) */
}
long buySellStocks2(long *val, int n, int tsFee)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // {start, buy}
    return f2(0, 1, val, n, dp, tsFee);
}

/* tabulation */
long buySellStocks2(long *val, int n, int tsFee)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // copy the base caes
    dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
            {
                // make sure it is long long
                profit = max(-val[ind] + dp[ind + 1][0],
                             0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(val[ind] - tsFee + dp[ind + 1][1],
                             0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }

    // {start, buy}
    return dp[0][1];
    /*  TC-O(n*2) SC-O(n*2) */
}

/* space otptimization */
long buySellStocks2(long *val, int n, int tsFee)
{
    vector<long> ahead(2, 0), curr(2, 0);

    // copy the base caes
    ahead[0] = ahead[1] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
            {
                // make sure it is long long
                profit = max(-val[ind] + ahead[0],
                             0 + ahead[1]);
            }
            else
            {
                profit = max(val[ind] - tsFee + ahead[1],
                             0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }

    // {start, buy}
    return ahead[1];
    /*  TC-O(n*2) SC-O(1) */
}

/* using variable */
long buySellStocks2(long *val, int n, int tsFee)
{
    long aheadNotBuy, aheadBuy, currNotBuy, currBuy;

    // copy the base caes
    aheadNotBuy = aheadBuy = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        // make sure it is long long

        // if
        currBuy = max(-val[ind] + aheadNotBuy,
                      0 + aheadBuy);

        // else
        currNotBuy = max(val[ind] - tsFee + aheadBuy,
                         0 + aheadNotBuy);

        // copy
        aheadNotBuy = currNotBuy;
        aheadBuy = currBuy;
    }

    return aheadBuy;
    /*  TC-O(n) SC-O(1) */
}