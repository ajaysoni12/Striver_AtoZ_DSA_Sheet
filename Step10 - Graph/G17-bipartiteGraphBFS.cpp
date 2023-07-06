#include <bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            // if adjacent node is not yet colored
            // you will give the opposite color
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            // if adjacent guy having same color
            // someone color it on the other path
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}
bool isBipartiteGraph(int V, vector<int> adj[])
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    // for multiple component
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (check(i, V, adj, color) == false)
                return false;
        }
    }
    return true;
    /*  TC-O(V + (V + 2E)) SC-O(V + V = 2V) */
}