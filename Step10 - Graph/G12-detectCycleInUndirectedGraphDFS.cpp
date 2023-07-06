#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;

    // go for it's neighbours
    for (auto adjancentNode : adj[node])
    {
        if (!vis[adjancentNode])
        {
            if (dfs(adjancentNode, node, vis, adj) == true)
                return true;
        }
        // if it is not parent, then it is have cycle
        else if (parent != adjancentNode)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0}; // 0-based index

    // for multiple component
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
    /*  TC-O(V + (V + 2E)) SC-O(V + V = 2V) */
}