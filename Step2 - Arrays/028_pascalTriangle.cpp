#include <bits/stdc++.h>
using namespace std;

/* 1st type: Given row and col, find which number is present overhear ? */
/* method 1 (brute force approach: generate all pascal triangle and find) */
/* method 2 (better solution: using NcR formula) */
int findFactorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
int findNcR(int n, int r)
{
    return (findFactorial(n) / (findFactorial(r) * findFactorial(n - r)));
}
int pascalTriangleRowCol(int row, int col)
{
    /*
        steps:
            1) find ncr
            2) find factorial
            3) return
    */

    return findNcR(row - 1, col - 1);
    /*  TC-O(n + r + (n-r) = 2n)
        SC-O(1) */
}

/* method 3 (optimal approach: only go till r time, because left of factorial is cancle) */
int pascalTriangleRowCol(int row, int col)
{
    // formuala: n-1 c r-1
    int n = row - 1, r = col - 1;
    int res = 1;
    for (int i = 1; i < r; i++)
    {
        // 10c3
        // 10*9*8 / 1*2*3
        res = res * (n - 1);
        res = res / (i + 1);
    }
    return res;
    /*  TC-O(r)
        SC-O(1) */
}

/* 2nd type: find the nth row of pascal triangle */
/* method 1 (brute force approach: uisng ncr) */
long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        // 10c3
        // 10*9*8 / 1*2*3
        res = res * (n - 1);
        res = res / (i + 1);
    }
    return res;
}
vector<long long> nthRowOfPascalTriangle(int n)
{
    vector<long long> ans;

    // nth row have nth element
    for (int col = 1; col <= n; col++)
        ans.push_back(nCr(n - 1, col - 1));
    return ans;
    /*  TC-O(n*r)
        SC-O(1 or n) */
}

/* method 2 (optimal approach: we need to add just little thing in prev ans) */
vector<long long> nthRowOfPascalTriangle(int n)
{
    const int mod = 1e9 + 7;
    long long ans = 1;

    vector<long long> res;
    if (n == 0)
        return res;
    if (n == 1)
        return {1};
    res.push_back(1);
    for (int i = 1; i < n; i++)
    {
        /*
            formula: 
                0 based indexing 
                and prev ans multiply by n-i
                and prev ans divided by col 
        */
        ans = ans * (n - i);
        ans = ans / (i);
        res.push_back(ans);
    }
    return res;
    /*  TC-O(n)
        TC-O(1) */
}

/* 3rd type: print pascal triangle */
/* method 1 (brute force approach: using ncr function) */
vector<vector<int>> printPascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> temp;
        for (int col = 1; col <= row; col++)
            temp.push_back(nCr(row - 1, col - 1));
        ans.push_back(temp);
    }
    return ans;
    /*  TC-O(n*n*r - o(n3) near about)
        SC-O(1) */
}

/* method 2 (optimal solution) */
vector<int> generateRow(int row)
{
    long long res = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        res = res * (row - col);
        res = res / col;
        ansRow.push_back(res);
    }
    return ansRow;
}
vector<vector<int>> printPascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> temp = generateRow(row);
        ans.push_back(temp);
    }
    return ans;
    /*  TC-O(n*n - o(n2) near about)
        SC-O(1) */
}