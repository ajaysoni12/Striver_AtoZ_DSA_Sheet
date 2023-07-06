#include <bits/stdc++.h>
using namespace std;

/* recursion */
int f1(int ind, int N, vector<int> &price)
{
    if (ind == 0)
        return N * price[0];

    int notTake = 0 + f1(ind - 1, N, price);
    int take = INT_MIN;
    if (price[ind] <= N)
        take = price[ind] + f1(ind, N - price[ind], price);

    return max(notTake, take);
    /*  TC-O(>>2^n) SC-O(N) */
}
int rodCutting(vector<int> &price, int N)
{
    return f1(price.size() - 1, N, price);
}

/* memoization */
int f2(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = 0 + f2(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        take = price[ind] + f2(ind, N - rodLength, price, dp);

    return dp[ind][N] = max(notTake, take);
    /*  TC-O(n*N) SC-O(n*N + N) */
}
int rodCutting(vector<int> &price, int N)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, -1));
    return f2(n - 1, N, price, dp);
}

/* tabulation */
int rodCutting(vector<int> &price, int N)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, 0));

    // base case
    for (int n = 0; n <= N; n++)
        dp[0][n] = n * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int n = 0; n <= N; n++)
        {
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + dp[ind][N - rodLength];

            dp[ind][N] = max(notTake, take);
        }
    }

    return dp[n - 1][N];
    /* TC-O(n*N) SC-O(n*N) */
}

/* space optimization */
int rodCutting(vector<int> &price, int N)
{
    int n = price.size();
    vector<int> prev(N + 1, 0), curr(N + 1, 0);

    // base case
    for (int n = 0; n <= N; n++)
        prev[n] = n * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int n = 0; n <= N; n++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + curr[N - rodLength];

            curr[N] = max(notTake, take);
        }
    }

    return prev[N];
    /* TC-O(n*N) SC-O(n + N) */
}

/* single array */
int rodCutting(vector<int> &price, int N)
{
    int n = price.size();
    vector<int> prev(N + 1, 0);

    // base case
    for (int n = 0; n <= N; n++)
        prev[n] = n * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int n = 0; n <= N; n++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + prev[N - rodLength];

            prev[N] = max(notTake, take);
        }
    }

    return prev[N];
    /* TC-O(n*N) SC-O(N) */
}