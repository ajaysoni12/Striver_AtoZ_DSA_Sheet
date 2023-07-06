#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using hashing) */
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
        if (a.first <= b.first)
            return true;
        else
            return false;
    return false;
}
vector<int> sortByFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // we can't sort map, that why use extra space
    vector<pair<int, int>> freq;
    for (auto it : mp)
        freq.push_back({it.first, it.second});

    // sort according to given two conditions
    sort(freq.begin(), freq.end(), cmp);

    vector<int> ans;
    for (auto it : freq)
    {
        int k = it.second;
        while (k--)
            ans.push_back(it.first);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> ans = sortByFreq(arr, n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
    /*  TC-O(t * (n + n + n*Logn))*/
}

/* method 2 (optimize approach: without using hashing) */
vector<int> sortByFreq()
{
    int n;
    cin >> n;

    vector<pair<int, int>> freq(61);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        freq[x].first = x;
        freq[x].second = (freq[x].second) + 1;
    }
    sort(freq.begin(), freq.end(), cmp);

    for (auto it : freq)
    {
        int t = it.second;
        while (t--)
            cout << it.first << " ";
    }
    cout << endl;
    /*  TC-O(t * (n + n*Log(n)))
        SC-O(n) */
}