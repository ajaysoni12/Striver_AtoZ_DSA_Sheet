#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: generate all possible permutation - n!)*/
vector<int> nextPermuation(vector<int> arr, int n)
{
    /*
        Steps:
            1) generate all sub_array
            2) linear search
            3) find permutation, and return next index
    */

    /*   TC-O(n!-all permutation * n(len of permutation))
         SC-O(n!) */
}

/* method 2 (better solution: using stl library, c++) */
vector<int> nextPermuation(vector<int> arr, int n)
{
    next_permutation(arr.begin(), arr.end());
    return arr;
    /*  TC- same as optimized */
}

/* method 3 (optimal apporach: implementaion of predefined func) */
vector<int> nextPermuation(vector<int> arr, int n)
{
    /*
        observation:
            1) find longer suffix match - ind = a[i] < a[i+1]
            2) find > ind, but the smallest once, so that you stay closed
            3) swap and reverse till ind+1 to end
    */

    // step1 - find break point
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    // step2 - edge case, if we not found break point
    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // step3 - find just greater than arr[ind], and swap
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    // step4 - reverse till ind+1 to end
    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
    /*  TC-O(n + n + n = 3n - near about)
        SC-O(1) */
}
