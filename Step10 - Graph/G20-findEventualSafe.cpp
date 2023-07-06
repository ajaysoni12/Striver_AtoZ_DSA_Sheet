#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    // tarverse for adjacent node
    for (auto it : adj[node])
    {
        // when the node not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis, check) == true)
            {
                check[node] = 0;
                return true;
            }
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        if (pathVis[it] == true)
        {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1; // safenode
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0}; // mark that it is safe node or not

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, pathVis, check);
    }

    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
        if (check[i] == 1)
            safeNodes.push_back(i);
    return safeNodes;
    /*  TC-O(V + (V + E)-directed) SC-O(V-component + V-vis + V-path + v= 4V) */
}