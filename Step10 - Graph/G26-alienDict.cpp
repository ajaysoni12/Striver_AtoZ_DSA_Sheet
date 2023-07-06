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

string alienDictionary(string dict[], int n, int K)
{
    vector<int> adj[K];

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
        }
    }

    vector<int> topo_sort = topoSort(K, adj);
    string ans = "";
    for (auto it : ans)
        ans = ans + char(it + 'a');
    return ans;
}