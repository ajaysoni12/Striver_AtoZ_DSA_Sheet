#include <bits/stdc++.h>
using namespace std;

/* Recursion */
int f1(int day, int last, vector<vector<int>> &points)
{
    // base case
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    // try out all possible way
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f1(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
    /*  TC-O(3^(n*4)) SC-O(n) */
}
int ninzaTraining(int n, vector<vector<int>> &points)
{
    return f1(n - 1, 3, points);
}

/* memoization */
int f2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // base case
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    // try out all possible way
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f2(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
    /*  TC-O((n*4)*3) SC-O(n + n*4) */
}
int ninzaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f2(n - 1, 3, points, dp);
}

/* Tabulation */
int ninzaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // start from day 1
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            int maxi = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }

            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
    /*  TC-O(n*4*3) SC-O(4) */
}

/* space optimization */
int ninzaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    // base case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // start from day 1
    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }

            curr[last] = maxi;
        }
        prev = curr;
    }

    return prev[3];
    /*  TC-O(n*4*3) SC-O(4) */
}
