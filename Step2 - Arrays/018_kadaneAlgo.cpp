#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: try out all possible subarray) */
int maxSubarrSum(vector<int> &arr, int n)
{
    // store max subarray sum
    int mx = INT_MIN;

    // for every ele
    for (int i = 0; i < n; i++)
    {
        // generate subarray
        for (int j = i; j < n; j++)
        {
            // find sum
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];

            // if sum is greater, updated
            mx = max(mx, sum);
        }
    }
    return mx;
    /*  TC-O(n^3 - near about)
        SC-O(1) */
}

/* method 2 (better approach: using two loops) */
int maxSubarrSum(vector<int> &arr, int n)
{
    // store max subarray sum
    int mx = INT_MIN;

    // for every ele
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // generate subarray
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            mx = max(mx, sum);
        }
    }
    return mx;
    /*  TC-O(n^2 - near about)
        SC-O(1) */
}

/* method 3 (optimal approach: kadane's algortihm) */
int maxSubarrSum(vector<int> &arr, int n)
{
    int bestSum = INT_MIN; // store max sum
    int currSum = 0;       // store curr-subarray sum

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        // update bestSum
        if (bestSum < currSum)
            bestSum = currSum;

        // if any moment currSum goes down to neg, put currSum = 0, we start new subArray
        if (currSum < 0)
            currSum = 0;
    }

    // if bestSum neg, then take empty subArray sum
    // if (bestSum < 0)
    //     bestSum = 0;
    return bestSum;
    /*  TC-O(n)
        SC-O(1) */
}

/* (find subArray whos give max subarray sum) */
int maxSubarrSum(vector<int> &arr, int n)
{
    int bestSum = INT_MIN; // store max sum
    int currSum = 0;       // store curr-subarray sum

    int ansStart = -1, ansEnd = -1;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (currSum == 0)
            start = i;
        currSum += arr[i];

        // update bestSum
        if (bestSum < currSum)
        {
            bestSum = currSum;
            ansStart = start, ansEnd = i;
        }

        // if any moment currSum goes down to neg, put currSum = 0, we start new subArray
        if (currSum < 0)
            currSum = 0;
    }

    // if bestSum neg, then take empty subArray sum
    // if (bestSum < 0)
    //     bestSum = 0;

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
        cout << arr[i] << " ";
    cout << "]\n";

    return bestSum;
    /*  TC-O(n)
        SC-O(1) */
}
