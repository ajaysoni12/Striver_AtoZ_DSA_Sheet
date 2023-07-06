#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // {{row, col}, time}
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if it is rotten orange then push into queue, at a time 0
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
                vis[i][j] = 0;
        }
    }

    int tm = 0;
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();

        // update time
        tm = max(t, tm);

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    // check all fresh orange is rotton or not
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
    }

    // or you can count fresh orange, and when push into queue you reduce if all fresh cnt will become 0, that means all fresh orange rotton

    // otherwise return minTime
    return tm;
    /*  TC-O(n*m + n*m*4) SC-O(n*m-vis + n*m-queue) */
}