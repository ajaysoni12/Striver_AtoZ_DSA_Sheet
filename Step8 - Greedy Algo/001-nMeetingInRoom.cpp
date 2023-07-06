#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start, end;
    int pos;
};

bool cmp(struct meeting m1, struct meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

void nMeeting(int s[], int e[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;

    sort(meet, meet + n, cmp);

    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].end);
        }
    }

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    /*  TC-O(n + nLogn + n)
        SC-O(3n = n) */
}