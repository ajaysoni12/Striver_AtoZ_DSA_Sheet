#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // count indegree
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo_sort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_sort.push_back(node);

        // node is in your topo_sort, so please remove it from the indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo_sort;
    /*  TC-O((V + E) + V + (V + E)) SC-O(V + V) */
}
 