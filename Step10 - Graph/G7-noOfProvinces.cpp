#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
}
int noOfProvinces(vector<vector<int>> adjMatrix, int V)
{
    // convert adjacency matrix to list
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && adjMatrix[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int vis[V] = {0};
    int cnt = 0;

    // O(v)
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, adj, vis); // O(V + 2E)
        }
    }
    return cnt;
    /*  TC-O(V + (V + 2E))
        SC-O(n-vis + n-recursion space = 2n) */
}