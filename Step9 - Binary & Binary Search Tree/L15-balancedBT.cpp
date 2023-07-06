#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

bool check(Node *root)
{
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
        return false;

    bool left = check(root->left);
    bool right = check(root->right);

    if (!left || !right)
        return false;

    return true;

    /*  TC-O(n(traversal) * n(find height-squeed tree) = n^2)
        SC-O(n - height of tree) */
}

/* if balanced return height otherwise return -1 */
int balancedTree(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = check(root->left);
    int rh = check(root->right);

    if (lh == -1 || rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
    /*  TC-O(n)
        SC-O(n-worst case) */
}