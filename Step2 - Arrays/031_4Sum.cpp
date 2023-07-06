#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: genrate all quadrate) */
vector<vector<int>> fourSum(vector<int> &arr, int n, int target)
{
    // for storing unique quadaret
    set<vector<int>> set;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k] + arr[l];

                    // if sum matched with target
                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        set.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(set.begin(), set.end());
    return ans;
    /*  TC-O(n*n*n*n = n^4 - near about)
        SC-O(no. of quadrate*2 (one for set and other for temp)) */
}

/* method 2 (better solution: using hashing) */
vector<vector<int>> fourSum(vector<int> &arr, int n, int target)
{
    // for storing unique quadaret
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // from j to k, store
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = arr[i] + arr[j] + arr[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    /*  TC-O(n*n*n = n^3(unordered_set) - near about or n^3*log(m) for set)
        SC-O(n) + O(no. of quadrate*2 (one fortzset and other for temp)) */
}

/* method 3 (optimal solution: using sorting, two pointer approach) */
vector<vector<int>> fourSum(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;

    // sort the array
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // remove duplicacy
        if (i > 0 and arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // remove duplicacy but next element se
            if (j != (i + 1) and arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);

                    // removing duplicacy
                    while (k < l and arr[k] == arr[k - 1])
                        k++;
                    while (k < l and arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
    /*  TC-O(n*n*n = n^3 - near about)
        SC-O(1) */
}