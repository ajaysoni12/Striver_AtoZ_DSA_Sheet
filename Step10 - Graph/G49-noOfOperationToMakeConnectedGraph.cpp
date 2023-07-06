#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{

    // for union by size
    vector<int> size;

public:
    vector<int> rank, parent;
    // work for 0 or 1-based indexing
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
        // o(4*alpha)
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        // belong to the same component
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            // you can do opposite as well
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        // o(4*alpha)
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        // belong to the same component
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        // o(4*alpha)
    }
};

int solve(int V, vector<vector<int>> &edge)
{
    DisjoinSet ds(V);
    int cntExtras = 0;

    // O(E * 4*aplha)
    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];

        if (ds.findUParent(u) == ds.findUParent(v))
            cntExtras++;
        else
            ds.unionBySize(u, v);
    }

    // O(V)
    int cntC = 0;
    for (int i = 0; i < V; i++)
        if (ds.parent[i] == i)
            cntC++;

    int ans = cntC - 1;
    if (cntExtras >= ans)
        return ans;
    return -1;
}