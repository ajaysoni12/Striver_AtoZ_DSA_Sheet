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

bool isValid(int adjr, int adjc, int n, int m)
{
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    DisjoinSet ds(n * m);

    int vis[n][m];
    memset(vis, 0, sizeof vis);

    int cnt = 0;
    vector<int> ans;

    for (auto it : operators)
    {
        int row = it[0];
        int col = it[1];

        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++; // assume it is diff component

        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        for (int ind = 0; ind < 4; ind++)
        {
            int adjr = row + dx[ind];
            int adjc = col + dy[ind];

            if (isValid(adjr, adjc, n, m))
            {
                if (vis[adjr][adjc] == 1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if (ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo))
                    {
                        cnt++;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}