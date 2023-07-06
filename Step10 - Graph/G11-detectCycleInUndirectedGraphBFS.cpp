#include <bits/stdc++.h>
using namespace std;

bool detecCycle(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;

    // {node, parent}
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // go for it's neighbours
        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if it is not a parent, that means someone already touch before me, it is cycle
            else if (parent != adjacentNode)
                return true;
        }
    }
    return false; // not a cycle
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0}; // 0-based indexing

    // it is have multiple component
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detecCycle(i, adj, vis) == true)
                return true;
        }
    }
    return false;
    /*  TC-O(V + (V + 2E)) SC-O(V + V = 2V) */
}