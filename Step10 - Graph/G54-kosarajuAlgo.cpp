#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, st);
    }
    st.push(node);
}
void dfs3(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // O(2*E)
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }

    // O(V + E)
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            // i ->it, it ->i
            adjT[it].push_back(i);
        }
    }

    // strongly connected component
    int scc = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs3(node, vis, adjT);
        }
    }
    return scc;
}