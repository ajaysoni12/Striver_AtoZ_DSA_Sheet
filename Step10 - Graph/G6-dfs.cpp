#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    // O(summision of all degree - 2E)
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ls); // O(for all nodes - n)
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;

    /*  TC-O(n-no. of node + 2E)
        SC-O(n-vis +n-ls + n-asc(squued graph) = 3n)
    */
}