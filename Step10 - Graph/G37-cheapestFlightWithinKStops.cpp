#include <bits/stdc++.h>
using namespace std;

int cheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];

    // directed graph
    for (auto it : flights)
        adj[it[0]].push_back({it[1], it[2]});

    // {stops, {node, dis}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // O(E) or O(flights.size()) - use queue that why logV remove
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k)
            continue;

        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            if (cost + edW < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}