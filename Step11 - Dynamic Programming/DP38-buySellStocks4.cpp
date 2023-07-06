#include <bits/stdc++.h>
using namespace std;

/* space optimization */
int buySellStocks4(vector<int> &price, int n, int k)
{
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    // no need of base cases, because it is already mark with 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // no need to start from 0, due to base case
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                    curr[buy][cap] = max(-price[ind] + after[0][cap],
                                         0 + after[1][cap]);
                else
                    curr[buy][cap] = max(price[ind] + after[1][cap - 1],
                                         0 + after[0][cap]);
            }
        }
        after = curr;
    }

    // {days, buy, transction}
    return after[1][k];
    /*  TC-O(n*2*K) SC-O(K*2) */
}

/* recursion */
int f1(int ind, int tranNo, vector<int> &price, int n, int k)
{
    // base case
    if (ind == n || (tranNo == 2 * k))
        return 0;

    // buy, even
    if (tranNo % 2 == 0)
        return max(-price[ind] + f1(ind + 1, tranNo + 1, price, n, k),
                   0 + f1(ind + 1, tranNo, price, n, k));

    // sell, odd
    return max(price[ind] + f1(ind + 1, tranNo + 1, price, n, k),
               0 + f1(ind + 1, tranNo, price, n, k));

    /*  TC-O(expo) SC-O(n) */
}
int buySellStocks4(vector<int> &price, int n, int k)
{
    return f1(0, 0, price, n, k);
}

/* memoization */
int f2(int ind, int tranNo, vector<int> &price, int n, int k, vector<vector<int>> &dp)
{
    // base case
    if (ind == n || (tranNo == 2 * k))
        return 0;

    if (dp[ind][tranNo] != -1)
        return dp[ind][tranNo];

    // buy, even
    if (tranNo % 2 == 0)
        return dp[ind][tranNo] = max(-price[ind] + f2(ind + 1, tranNo + 1, price, n, k, dp),
                                     0 + f2(ind + 1, tranNo, price, n, k, dp));

    // sell, odd
    return dp[ind][tranNo] = max(price[ind] + f2(ind + 1, tranNo + 1, price, n, k, dp),
                                 0 + f2(ind + 1, tranNo, price, n, k, dp));

    /*  TC-O(n*2*k) SC-O(n*2*k + n) */
}
int buySellStocks4(vector<int> &price, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return f2(0, 0, price, n, k, dp);
}

/* tabulation */
int buySellStocks4(vector<int> &price, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    // no-need to explictily write base case, by default zero's

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            // buy, even
            if (tranNo % 2 == 0)
                dp[ind][tranNo] = max(-price[ind] + dp[ind + 1][tranNo + 1],
                                      0 + dp[ind + 1][tranNo]);

            // sell, odd
            else
                dp[ind][tranNo] = max(price[ind] + dp[ind + 1][tranNo + 1],
                                      0 + dp[ind + 1][tranNo]);
        }
    }

    return dp[0][0];
    /*  TC-O(n*2*k) SC-O(n*2*k) */
}

/* space optimization */
int buySellStocks4(vector<int> &price, int n, int k)
{
    vector<int> after(2 * k + 1, 0), curr(2 * k + 1, 0);

    // no-need to explictily write base case, by default zero's

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            // buy, even
            if (tranNo % 2 == 0)
                curr[tranNo] = max(-price[ind] + after[tranNo + 1],
                                   0 + after[tranNo]);

            // sell, odd
            else
                curr[tranNo] = max(price[ind] + after[tranNo + 1],
                                   0 + after[tranNo]);
        }
    }

    return after[0];
    /*  TC-O(n*2*k) SC-O(2*k + 2*k) */
}
