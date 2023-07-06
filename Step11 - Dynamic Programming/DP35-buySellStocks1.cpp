#include <bits/stdc++.h>
using namespace std;

int buySellStocks1(vector<int> &price, int n)
{
    int mini = price[0], profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = price[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, price[i]);
    }
    return profit;
    /*  TC-O(n) SC-O(n) */
}