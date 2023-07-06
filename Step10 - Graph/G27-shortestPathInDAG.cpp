#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
            topoSort(v, adj, vis, st);
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<int> edges[])
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // find the topo_sort
    int vis[N] = {0};
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            topoSort(i, adj, vis, st);
    }

    // find shortest dictance, O(N + E)
    vector<int> dist(N);
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX; // or 1e9
    dist[0] = 0;

    // O(N + M or E)
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }
    return dist;
}