#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool solve(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return solve(left->left, right->right) && solve(left->right, right->left);
}
bool isSymmetricBT(Node *root)
{
    return root == NULL || solve(root->left, root->right);
    /*  TC-O(n)
        SC-O(h - squeed tree) */
}
