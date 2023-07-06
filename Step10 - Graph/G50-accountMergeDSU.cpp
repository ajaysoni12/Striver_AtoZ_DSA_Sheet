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

vector<vector<string>> mergeDetails(vector<vector<string>> &details)
{
    int n = details.size();
    unordered_map<string, int> mapMailNode;
    DisjoinSet ds(n);

    // create graph, and maping
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end())
                mapMailNode[mail] = i;
            else
                ds.unionBySize(i, mapMailNode[mail]);
        }
    }

    // create structure, who is part of whom
    vector<string> mergeMail[n];
    for (auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findUParent(it.second);
        mergeMail[node].push_back(mail);
    }

    // find
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergeMail[i].size() == 0)
            continue;

        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for (auto it : mergeMail[i])
            temp.push_back(it);
        ans.push_back(temp);
    }
    return ans;
}