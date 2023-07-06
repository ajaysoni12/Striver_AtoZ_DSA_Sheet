#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1]; // 1-based indexing
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    pq.push({0, 1}); // src-1
    dist[1] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[n] == 1e9)
        return {-1};

    vector<int> path;
    int node = n;

    // o(n)
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1); // loop-end, that's why insert src ndoe
    reverse(path.begin(), path.end());
    return path;
    /*  TC-O(E+LogV + N) SC-O(n+n + n + n = n) */
}