#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* level order traverse - o(n) o(n) */

int depthOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = depthOfTree(root->left);
    int rh = depthOfTree(root->right);

    return 1 + max(lh, rh);
    /*  TC-O(n)
        SC-O(height or n-for squeed tree) */
}