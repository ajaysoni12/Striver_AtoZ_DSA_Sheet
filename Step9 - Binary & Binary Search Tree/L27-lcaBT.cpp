#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (store paths of both the nodes) */

bool getPath(Node *root, vector<int> &ans, int x)
{
    if (root == NULL)
        return true;

    ans.push_back(root->data);

    if (root->data == x)
        return true;

    if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
    /*  TC-O(n) SC-O(n) */
}
int lca(Node *root, int val1, int val2)
{
    vector<int> path1, path2;
    getPath(root, path1, val1);
    getPath(root, path2, val2);

    if (path1.size() == 0 || path2.size() == 0)
        return -1;

    // edge case
    if (path1.size() == 1 || path2.size() == 1)
        return path1[0];

    int size = min(path1.size(), path2.size());
    for (int i = 1; i < size; ++i)
    {
        if (path1[i] != path2[i])
            return path1[i - 1];
    }
    return -1;
    /*  TC-O(n + n = 2n)
        SC-O(n + n = 2n) */
}

/* method 2 (space optimize) */
Node *lcaBT(Node *root, Node *p, Node *q)
{
    // base case
    if (root == NULL || root == p || root == q)
        return root;

    Node *left = lcaBT(root->left, p, q);
    Node *right = lcaBT(root->right, p, q);

    // result
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // both left and right is not null, means result found
    /*  TC-O(n) SC-O(n) */
}