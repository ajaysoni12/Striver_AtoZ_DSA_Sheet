#include <bits/stdc++.h>
using namespace std;

class DisjoinSet
{
public:
    // for union by size
    vector<int> size;
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

bool isValid(int nrow, int ncol, int n)
{
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
}

int makingLargeLand(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjoinSet ds(n * n);

    // step-1, create disjoin set component
    // o(n*n*4)
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;

            int dx[] = {-1, 0, +1, 0};
            int dy[] = {0, +1, 0, -1};
            for (int ind = 0; ind < n; ind++)
            {
                int nrow = row + dx[ind];
                int ncol = col + dy[ind];

                if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = nrow * n + ncol;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    // step-2, O(n*n*4)
    int mx = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;

            set<int> components; // O(logn - neglizbale)

            int dx[] = {-1, 0, +1, 0};
            int dy[] = {0, +1, 0, -1};
            for (int ind = 0; ind < 4; ind++)
            {
                int nrow = row + dx[ind];
                int ncol = col + dy[ind];

                if (isValid(nrow, ncol, n))
                    if (grid[nrow][ncol] == 1)
                        components.insert(ds.findUParent(nrow * n + ncol));
            }
            int totalSize = 0;
            for (auto it : components)
                totalSize += ds.size[it];
            mx = max(mx, totalSize + 1);
        }
    }

    for (int cellNo = 0; cellNo < n * n; cellNo++)
        mx = max(mx, ds.size[ds.findUParent(cellNo)]);
    return mx; 
}