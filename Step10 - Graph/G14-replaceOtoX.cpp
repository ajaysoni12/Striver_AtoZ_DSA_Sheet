#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis)
{
    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();

    // all four direction
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            dfs(nrow, ncol, mat, vis);
    }
}
vector<vector<char>> repalceOtoX(vector<vector<char>> mat, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // traverse first row and last column
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] && mat[0][j] == 'O')
            dfs(0, j, mat, vis);

        // last row
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            dfs(n - 1, j, mat, vis);
    }

    // traverse first col and last col
    for (int i = 0; i < n; i++)
    {
        // first col
        if (!vis[i][0] && mat[i][0] == 'O')
            dfs(i, 0, mat, vis);

        // last col
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            dfs(i, m - 1, mat, vis);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && mat[i][j] == 'O')
                mat[i][j] = 'X';

    return mat;
    /*  TC-O(n + m + n*m + n*m*4-queue) SC-O(n*m-vis + n*m-rec) */
}