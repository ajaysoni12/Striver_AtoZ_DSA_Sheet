#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }
    st.push(node); // 1->2->3->4 4->5 or 4->6, complete traverse then push into queue
}
vector<int> topologicalSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, st, adj);
    }

    vector<int> topo_sort;
    while (!st.empty())
    {
        topo_sort.push_back(st.top());
        st.pop();
    }
    return topo_sort;
    /*  TC-O(V + (V + E)-dir) SC-O(V-vis + V-st + V-rec) */
}