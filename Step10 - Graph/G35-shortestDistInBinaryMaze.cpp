#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    int n = grid.size();
    int m = grid[0].size();

    // {dist, {row, col}}
    // no need of pq, because distance increase by linear
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
            {
                dist[nrow][ncol] = dis + 1;

                // if it is destination node
                if (nrow == destination.first && ncol == destination.second)
                    return dis + 1;

                q.push({dis + 1, {nrow, ncol}});
            }
        }
    }
    return -1; // not reac, destination node
    /* TC-O(E*LogV*4) SC-O(n*n + n*n) */
}