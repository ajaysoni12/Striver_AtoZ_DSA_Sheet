#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    int dx[] = {+1, 0, 0, -1};
    int dy[] = {0, -1, +1, 0};

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nextI = i + dx[ind];
        int nextJ = j + dy[ind];

        if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n &&
            !vis[nextI][nextJ] && mat[nextI][nextJ] == 1)
        {
            vis[i][j] = 1;
            solve(nextI, nextJ, mat, n, ans, move + dir[ind], vis);
            vis[i][j] = 0;
        }
    }
}
vector<string> rateInMaze(vector<vector<int>> &mat, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (mat[0][0])
        solve(0, 0, mat, n, ans, "", vis);
    return ans;
    /*  TC-O(4^(n*m))
        SC-O(n*m) */
}