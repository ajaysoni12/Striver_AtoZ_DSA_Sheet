#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src)
{
    vector<int> adj[n];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = 1e9;

    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1e9)
            ans[i] = dist[i];
    }
    return ans;
    /*  TC-O(M + N + (N+2E) + N) SC-O(2N + N + N = 4N) */
}