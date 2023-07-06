#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{
    vector<int> rank, parent;

    // for union by size
    vector<int> size;

public:
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

int main()
{
    DisjoinSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "\nSame";
    else
        cout << "\nNot Same";

    ds.unionBySize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "\nSame";
    else
        cout << "\nNot Same";
    return 0;
}