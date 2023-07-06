#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int iniColor, int newColor, int dx[], int dy[])
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    // visit it's all 4 neighbours
    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            dfs(nrow, ncol, image, ans, iniColor, newColor, dx, dy);
    }
}
vector<vector<int>> floodFill(int sr, int sc, vector<vector<int>> &image, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image; // O(n*m)

    // all four direction
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    dfs(sr, sc, image, ans, iniColor, newColor, dx, dy);
    return ans;
    /*  TC-O(n*m + n*m*4) SC-O(n*m-ans + n*m-recursion space) */
}