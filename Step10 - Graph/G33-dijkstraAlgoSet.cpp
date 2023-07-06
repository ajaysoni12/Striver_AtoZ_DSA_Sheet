#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(int V, vector<vector<int>> adj[], int src)
{
    set<pair<int, int>> set;
    vector<int> dist(V, 1e9);

    set.insert({0, src});
    dist[src] = 0;

    while (!set.empty())
    {
        auto it = *(set.begin());
        int node = it.second;
        int dis = it.first;
        set.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];

            if (dis + edgeWeight < dist[adjNode])
            {
                // else if it is exist
                if (dist[adjNode] != 1e9)
                    set.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgeWeight;
                set.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
    /*  TC-O(E*LogV) SC-O(n) */

    /*

    O(v * (pop out from min-heap + no. of edges on each vertex * push in pq))

    O(v * (log(heap-size) + ne * log(heap-size)))

    O(v * (log(heap-size) * (ne(v-1) + 1)))

    O(v * v * log(heap-size))
    O(v^2 * log(heap-size))
    o(v^2 * log(v^2)) O(v^2 * 2*l)
    O(E * 2LogV) = O(E * LogV)

    */
}