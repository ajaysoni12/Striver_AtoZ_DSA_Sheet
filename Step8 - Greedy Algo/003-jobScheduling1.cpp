#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

pair<int, int> jobScheduling1(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int maxDeadLine = arr[0].deadline;
    for (int i = 1; i < n; i++)
        maxDeadLine = max(maxDeadLine, arr[i].deadline);

    int slots[maxDeadLine + 1];
    for (int i = 0; i <= maxDeadLine; i++)
        slots[i] = -1;

    int cntJob = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                cntJob++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return make_pair(cntJob, jobProfit);
    /*  TC-O(nLogn + n*m)
        SC-O(m) m, max deadline */
}