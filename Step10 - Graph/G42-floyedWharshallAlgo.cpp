#include <bits/stdc++.h>
using namespace std;

void floyedWharshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // it is question needed
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if (i == j)
                matrix[i][j] = 0; // node-to-node, dist is zero
        }
    }

    // apply floyed wharshall algo
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    // find negative cycle
    for (int i = 0; i < n; i++)
        if (matrix[i][i] < 0)
            cout << "Negative cycle exist";

    // it is question need
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
    /*  TC-O(n*n + n*n*n + n*n = n^3) SC-O(n*n - given matrix) */
}