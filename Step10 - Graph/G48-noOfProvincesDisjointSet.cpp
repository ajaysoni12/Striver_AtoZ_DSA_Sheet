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

int numProvinces(vector<vector<int>> adj, int V)
{
    DisjoinSet ds(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // i->j
            ds.unionBySize(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < V; i++)
        if (ds.parent[i] == i) // you can use find parent also
            cnt++;

    return cnt;
    /* TC-O(N*N + N) SC-O(N+N=2N)*/
}