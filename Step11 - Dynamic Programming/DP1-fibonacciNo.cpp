#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int n)
{
    if (n <= 1)
        return n;

    return f1(n - 1) + f1(n - 2);
    /*  TC-O(2^n) SC-O(n) */
}

/* Memoization */
int f2(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // check previously computed or not,
    if (dp[n] != -1)
        return dp[n];

    // store fibo no of n
    return dp[n] = f2(n - 1, dp) + f2(n - 2, dp);

    /*  TC-O(n - lineary computation, n, n-1, n-2, n-3,...1, 0)
        SC-O(n-rec + n-dp) */
}

/* Tabulation */
int f3(int n, vector<int> &dp)
{
    // base case
    dp[0] = 0;
    dp[1] = 1;

    // copy the recurence relation
    // need to computer from 2, before 2 already compute
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
    /*  TC-O(n) SC-O(n-dp) */
}

int f4(int n)
{
    // store two previous steps, or call base case
    int prev2 = 0;
    int prev1 = 1;

    // we need just two previous values
    for (int i = 2; i <= n; i++)
    {
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }

    // answer will store in prev1
    return prev1;
    /*  TC-O(n) SC-O(1) */
}

int main()
{
    int n;
    cin >> n;

    // For Recursion
    cout << f1(n) << endl;

    // For Memoization
    vector<int> dp1(n + 1, -1);
    cout << f2(n, dp1) << endl;

    // For Tabulation
    vector<int> dp2(n + 1, 0);
    cout << f3(n, dp2) << endl;

    // For Space Optimization 
    cout << f4(n) << endl; 
}