#include <bits/stdc++.h>
using namespace std;

/* method 1 (otpimal solution: implementaiton)*/
vector<int> sprialMatrix(vector<vector<int>> &mat)
{
    // setp1 - find row, col
    int n = mat.size();
    int m = mat[0].size();

    // step2 - take all 4 direction
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int> ans;

    while (left <= right and top <= bottom)
    {
        // right
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        // left
        if (top <= bottom) // we have just single row
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }

        // top
        if (left <= right) // we not have upp
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans; 
    /*  TC-O(n*m) 
        SC-O(n) */
}
