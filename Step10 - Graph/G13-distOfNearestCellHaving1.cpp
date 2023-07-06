#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    // {{row, col}, steps}
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0}); // self distance is 0
                vis[i][j] = 1;
            }
            else
                vis[i][j] = 0;
        }
    }

    // all 4-direction
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        // mark distance
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1}); // +1 distance extra
            }
        }
    }

    return dist;
    /*  TC-O(n*m + n*m*4) SC-O(n*m-vis + n*m-dist + n*m-queue) */
}