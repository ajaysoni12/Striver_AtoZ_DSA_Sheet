#include <bits/stdc++.h>
using namespace std;

int minEfforts(vector<vector<int>> &heights)
{

    int n = heights.size();
    int m = heights[0].size();

    // {diff, {row, col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, int>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    // O(E*LogV) or O(n*m*4 * log (n*m))
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.top();

        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int newEffort = max(diff, abs(heights[row][col] - heights[nrow][ncol]));

                if (newEffort < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return 0; // not reacable
}