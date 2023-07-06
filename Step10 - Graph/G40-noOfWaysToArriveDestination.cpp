#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // min-heap,
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {dis, node}
    pq.push({0, 0});

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    int mod = (int)(1e9 + 7);
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            // this is first time, i am coming with the short distance
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }

            // no need of pushing agian in pq
            else if (dis + edW == dist[adjNode])
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
        }
    }
    return ways[n - 1] % mod;
}