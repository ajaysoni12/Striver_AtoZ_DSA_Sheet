#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in the neighbours and mark them if it is lands
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cntIslands = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                cntIslands++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cntIslands;
    /*  TC-O(n*m + n*m*9 = 9*n*m) SC-O(n*m + n*m = 2n*m)  */
}

/* dfs */
bool isSafe(int i, int j, int n, int m)
{
    if (i >= 0 and j >= 0 and i < n and j < m)
        return true;
    return false;
}
void dfs(int i, int j, vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis)
{   
    vis[i][j] = true;
    // cout << i << " " << j << endl;
    int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int k = 0; k < 8; k++)
    {
        int nrow = i + dx[k];
        int ncol = j + dy[k];
        if (isSafe(nrow, ncol, n, m) and grid[nrow][ncol] == '1' and !vis[nrow][ncol])
            dfs(nrow, ncol, grid, n, m, vis);
    }
}