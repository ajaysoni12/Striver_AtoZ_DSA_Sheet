#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<vector<int>> setMatrixZero(vector<vector<int>> &mat, int n, int m)
{
    // step1 - traverse matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if find zero, then fill -1 into row & col, remember
            // it is already zero, then do nothing
            if (mat[i][j] == 0)
            {
                // step3 - fill row and col
                // makeRow(i);
                for (int j = 0; j < m; j++)
                    if (mat[i][j] != 0)
                        mat[i][j] = -1;

                // makeCol(j);
                for (int i = 0; i < n; i++)
                    if (mat[i][j] != 0)
                        mat[i][j] = -1;
            }
        }
    }

    // step4 - again iterate, and fill 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
    return mat;
    /*  TC-O(n*m*(n+m) + n*m = n^3-near about)
        SC-O(1) */
}

/* method 2 (better solution: using marking approach) */
vector<vector<int>> setMatrixZero(vector<vector<int>> &mat, int n, int m)
{
    // step1 - just keep track of row, col
    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // step2 - mat coltain 0, then track this row, col fill up with 0, so put 1 overhear
            if (mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // step3 - now fill 0's
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if row or col marking then put 0
            if (row[i] || col[j])
                mat[i][j] = 0;
        }
    }
    return mat;
    /*  TC-O(n*m + n*m = 2*n*m)
        SC-O(n + m) */
}

/* method 3 (optimal solution: without extra space) */
vector<vector<int>> setMatrixZero(vector<vector<int>> &mat, int n, int m)
{
    // int row[n] = {0} -> mat[...][0]
    // int col[m] = {0} -> mat[0][...]

    int col0 = 1; // mat[0][0]
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < m; j++)
        {
            // if it's 0, the keep track
            if (mat[i][j] == 0)
            {
                // mark with ith row
                mat[i][0] = 0;
                // mark with jth col
                if (j != 0) // for 0 index we have extra variable
                    mat[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // step2 - mark from 1 - n and 1 - m
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                // check for row and col
                if (mat[i][0] == 0 or mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }
    }

    // step3 - first mark for rows, because it's not affected
    if (mat[0][0] == 0)
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;

    // step4 - mark with col
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }

    /*  TC-O(n*m + n*m= 2*n*m )
        SC-O(1) */
}
 