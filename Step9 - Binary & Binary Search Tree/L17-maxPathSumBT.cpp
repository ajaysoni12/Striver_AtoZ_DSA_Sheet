#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int maxPathSum(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    // if path sum neg, then take 0, becuase of neg not give max path sum
    int left = max(0, maxPathSum(root->left, maxi));
    int right = max(0, maxPathSum(root->right, maxi));
    maxi = max(maxi, left + right + root->data);
    return max(left, right) + root->data;
    /*  TC-O(n)
        SC-O(n) */
}