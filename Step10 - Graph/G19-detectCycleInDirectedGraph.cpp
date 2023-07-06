#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    // tarverse for adjacent node
    for (auto it : adj[node])
    {
        // when the node not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        if (pathVis[it] == true)
            return true;
    }

    pathVis[node] = 0;
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis) == true)
                return true;
        }
    }
    return false;
    /*  TC-O(V + (V + E)-directed) SC-O(V-component + V-vis + V-path = 3V) */
}