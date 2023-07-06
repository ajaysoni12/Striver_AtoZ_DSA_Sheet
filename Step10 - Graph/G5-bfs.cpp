#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> bfs;

    // intial confrugration
    bool vis[v] = {false}; // for 0-based index
    queue<int> q;
    q.push(0);
    vis[0] = 1; 

    // O(no. of nodes v)
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // O(2E)-total time traverse, 
        for (auto it : adj[node])
        {
            // previously not visited
            if (vis[it] == false)
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;

    /*  TC-O(v + 2E) SC-O(n-vis + n-queue + n-bfs = 3n) */
}