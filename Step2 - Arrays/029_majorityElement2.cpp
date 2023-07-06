#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<int> majorityEle2(vector<int> &nums, int n)
{
    vector<int> ls;

    // cnt how many time it's present
    for (int i = 0; i < n; i++)
    {
        // if ls is empty or last ele is not equal so continue
        if (ls.size() == 0 or ls[0] != nums[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    cnt++;
            }

            // if any movement cnt is greater than n/3 times push_back into answer
            if (cnt > n / 3)
                ls.push_back(nums[i]);
        }

        // and size is equal to 2 then break;
        if (ls.size() == 2)
            break;
    }
    return ls;
    /*  TC-O(n*n = n^2 - near about)
        SC-O(1) */
}

/* method 2 (better solution: using hashing) */
vector<int> majorityEle2(vector<int> &nums, int n)
{
    // track of freq of each ele
    map<int, int> mp;

    // mini freq we need for freq greater than n / 3 times
    int min = (n / 3) + 1;

    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] == min)
            ls.push_back(nums[i]);
    }
    return ls;
    /*  TC-O(n*log(n) or n(unordered_map))
        SC-O(n) */
}

/* method 3 (optimal solution: using moore voting algo) */
vector<int> majorityEle2(vector<int> &nums, int n)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 and nums[i] != ele2)
        {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 and nums[i] != ele1)
        {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if (nums[i] == ele1)
            cnt1++;
        else if (nums[i] == ele2)
            cnt2++;
        else
            cnt1--, cnt2--;
    }

    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (ele1 == nums[i])
            cnt1++;
        if (ele2 == nums[i])
            cnt2++;
    }

    int min = ((int)n / 3) + 1;
    if (cnt1 >= min)
        ls.push_back(ele1);
    if (cnt2 >= min)
        ls.push_back(ele2);
    return ls;
    /*  TC-O(n + n = 2n) 
        SC-O(1) */
}