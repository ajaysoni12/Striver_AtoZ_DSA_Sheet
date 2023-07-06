#include <bits/stdc++.h>
using namespace std;

int minMultipliationToreachEnd(vector<int> &arr, int start, int end)
{
    // no need of pq, lineary increase
    queue<pair<int, int>> q;
    q.push({start, 0}); // {node, steps}

    int mod = 1e5;
    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int num = (it * node) % mod;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1; 
    /*  TC-O(E * arr.size() or 1e5*n) SC-O(1e5 + 1e5)*/
}