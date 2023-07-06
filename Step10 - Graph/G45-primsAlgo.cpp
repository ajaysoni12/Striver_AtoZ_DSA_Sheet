#include <bits/stdc++.h>
using namespace std;

int minSpanningTree(int V, vector<vector<int>> adj[])
{
    // {wt, node} for mst (wt, node, parent)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // parent -1;

    vector<int> vis(V, 0);

    int sum = 0;

    // O(E)
    while (!pq.empty())
    {
        // O(E * LogV)
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;
        // here you can addup mst(parent, node)

        // O(E * LogV)
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edw = it[1];

            if (!vis[adjNode])
                pq.push({edw, adjNode});
        }
    }
    return sum;
    /*  TC-O(E*logV)*/
}