#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
int maxProfit(vector<int> &arr, int n)
{
    int profit = 0; // store max profit

    // try out all index to buy
    for (int i = 0; i < n; i++)
    {
        // find best day, to sell it
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
                profit = max(profit, arr[j] - arr[i]);
        }
    }

    return profit;
    /*  TC-O(n^2)
        SC-O(1)  */
}

/* method 2 (optimal approach: keep track of miniBuyDay) */
int maxProfit(vector<int> &arr, int n)
{
    int mini = arr[0]; // keep track of min buy day
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;   // find cost
        profit = max(profit, cost); // update profit
        mini = min(mini, arr[i]);   // update min day
    }

    return profit;
    /*  TC-O(n)
        SC-O(1) */
}