#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
int missingNumber(vector<int> &nums, int n)
{
    // for every index
    for (int i = 0; i < n; i++)
    {
        // find if it is exist or not
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                flag = true;
                break;
            }
        }

        // not exist
        if (flag == false)
            return i;
    }
    return -1;
    /*  TC-O(n*n) - hypothetically, becuase some time we break the inner loop
        SC-O(1) */
}

/* method 2 (better solution: using hashing) */
int missingNumber(vector<int> &nums, int n)
{
    // step1 - declare hash array of n+1
    int hashArr[n + 1] = {0};

    // step2 - go till n-1 because array contain n-1 element
    for (int i = 0; i < n - 1; i++)
        hashArr[nums[i]] = 1;

    // step3 - find which one contain 0
    for (int i = 1; i <= n; i++)
        if (hashArr[i] == 0)
            return i;

    return -1;
    /*  TC-O(n + n = 2n)
        SC-O(n) */
}

/* method 3 (optimal_1 approach: getting sum) */
int missingNumber(vector<int> &nums, int n)
{
    // step1 - find total first n natural sum
    int sum = (n * (n + 1)) / 2;

    // step2 - find total array sum
    int currSum = 0;
    for (int i = 0; i < n; i++)
        currSum += nums[i];

    // step3 - diff b/w sum - currSum is your missing number
    return sum - currSum;
    /*  TC-O(n)
        SC-O(1) */
}

/* method 4 (optimal_2 approach: using xor) */
// better than prev optimal solution because of we computer sum of first natraul num, image n is 1e5, then sum is near about 1e10, we need to store in long data type 
int missingNumber(vector<int> &nums, int n)
{
    // step1 - find xor of first 'n' natural number
    int xor1 = 0;
    for (int i = 1; i <= n; i++)
        xor1 ^= i;

    // step2 - find xor of all ele in array
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
        xor2 ^= nums[i];

    // step3 - xor both of the variable we get our missing number
    return xor1 ^ xor2;

    /*  TC-O(n + n = 2n)
        SC-O(1) */

    // optimize time complexity
    int xor1 = 0, xor2 = 0;

    // find xor of array, and symultaneaouly comput xor of natural number
    for (int i = 0; i < n - 1; i++)
    {
        xor2 ^= nums[i];
        xor1 ^= (i + 1);
    }

    // last nth number is not xor, so do it
    xor1 ^= n;
    return xor1 ^ xor2;
    /*  TC-O(n)
        SC-O(1) */
}