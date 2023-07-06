#include <bits/stdc++.h>
using namespace std;

bool isSafe1(int row, int col, vector<string> board, int n)
{
    int dupRow = row;
    int dupCol = col;

    // check upper left diagonal, o(n) operation
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // check in left direction, o(n) operation
    row = dupRow;
    col = dupCol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // check in lower left diagonal, o(n) operation
    row = dupRow;
    col = dupCol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }

    // here queen can be placed
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.'; // remove queen, try next option
        }
    }
}
vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string str(n, '.');

    for (int i = 0; i < n; i++)
        board[i] = str;

    solve(0, board, ans, n);
    /*  TC-O(n^2 + n*n*3n = n^2 + 3n^3)
        SC-O(n*n + n) */
}

/* method 2 (optimize appraoch: using hashing) */
void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 + row - col] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + row - col] = 1;
            solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal,n);
            board[row][col] = '.'; // remove queen, try next option
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + row - col] = 0;
        }
    }
}
vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string str(n, '.');

    for (int i = 0; i < n; i++)
        board[i] = str;

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
    return ans; 
    /*  TC-O(n^2 + n*n = n^2 + n^2 = 2n^2)
        SC-O(n*n + n + n + 2*n-1 + 2*n-1) */
}
