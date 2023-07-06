#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int buy, int cap, vector<int> &price, int n)
{
    // base case
    if (ind == n || cap == 0)
        return 0;

    if (buy)
        return max(-price[ind] + f1(ind + 1, 0, cap, price, n),
                   0 + f1(ind + 1, 1, cap, price, n));

    // else
    return max(price[ind] + f1(ind + 1, 1, cap - 1, price, n),
               0 + f1(ind + 1, 0, cap, price, n));

    /*  TC-O(expo - 2^n) SC-O(n) */
}
int buySellStocks3(vector<int> &price, int n)
{
    // {days, buy, transction}
    return f1(0, 1, 2, price, n);
}

/* memoization */
int f2(int ind, int buy, int cap, vector<int> &price, int n, vector<vector<vector<int>>> &dp)
{
    // base case
    if (ind == n || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy)
        return dp[ind][buy][cap] = max(-price[ind] + f2(ind + 1, 0, cap, price, n, dp),
                                       0 + f2(ind + 1, 1, cap, price, n, dp));

    // else
    return dp[ind][buy][cap] = max(price[ind] + f2(ind + 1, 1, cap - 1, price, n, dp),
                                   0 + f2(ind + 1, 0, cap, price, n, dp));

    /*  TC-O(n*3*2) SC-O(n*3*2 + n) */
}
int buySellStocks3(vector<int> &price, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    // {days, buy, transction}
    return f2(0, 1, 2, price, n, dp);
}

/* tabulation */
int buySellStocks3(vector<int> &price, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // no need of base cases, because it is already mark with 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // no need to start from 0, due to base case
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                    dp[ind][buy][cap] = max(-price[ind] + dp[ind + 1][0][cap],
                                            0 + dp[ind + 1][1][cap]);
                else
                    dp[ind][buy][cap] = max(price[ind] + dp[ind + 1][1][cap - 1],
                                            0 + dp[ind + 1][0][cap]);
            }
        }
    }

    // {days, buy, transction}
    return dp[0][1][2];
    /*  TC-O(n*2*3) SC-O(n*2*3) */
}

/* space optimization */
int buySellStocks3(vector<int> &price, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    // no need of base cases, because it is already mark with 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // no need to start from 0, due to base case
            for (int cap = 1; cap <= 2; cap++)
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
    return after[1][2];
    /*  TC-O(n*3*2) SC-O(3*2) */
}

/* further otptimization (using memoization) */
/*
    B S B S
    0 1 2 3
    e o e o
*/

int f3(int ind, int transction, vector<int> &price, int n)
{
    if (ind == n || transction == 4)
        return 0;

    // buy
    if (transction % 2 == 0)
        return max(-price[ind] + f3(ind + 1, transction + 1, price, n),
                   0 + f3(ind + 1, transction, price, n));
    // sell
    else
        return max(price[ind] + f3(ind + 1, transction + 1, price, n),
                   0 + f3(ind + 1, transction, price, n));
}