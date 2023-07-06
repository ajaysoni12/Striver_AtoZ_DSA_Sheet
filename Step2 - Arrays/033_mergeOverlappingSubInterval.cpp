#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using sorting) */
vector<vector<int>> overlapInterval(vector<vector<int>> &interval)
{
    int n = interval.size();

    // sort interval, {4,7} {4,5} --> {4,5}, {4,7}
    sort(interval.begin(), interval.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = interval[i][0];
        int end = interval[i][1];

        // if this index value already merged
        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // this interval should be merged
            if (interval[j][0] <= end)
                end = max(end, interval[j][1]); // take max end value
            else
                break; // it is sorted, if conditions failed then break out
        }
        ans.push_back({start, end});
    }
    return ans;
    /*  TC-O(nLog(n) + n^2-near about but it's is exact-2n(visit only two tiems))
        SC-O(n - for storing ans) */
}

/* method 2 (optimize approach: using single traverse) */
vector<vector<int>> overlapInterval(vector<vector<int>> &interval)
{
    int n = interval.size();

    // sort interval, {4,7} {4,5} --> {4,5}, {4,7}
    sort(interval.begin(), interval.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = interval[i][0];
        int end = interval[i][1];

        if (ans.empty() || start > ans.back()[1])
            ans.push_back(interval[i]);
        else
            ans.back()[1] = max(ans.back()[1], end);
    }
    return ans;
    /*  TC-O(nLog(n) + n^2-near about but it's is exact-n(visit only only tiems))
        SC-O(n - for storing ans) */
}