#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isValidBST(Node *root, long minVal, long maxVal)
{
    if (root == NULL)
        return true;

    if (root->data >= maxVal || root->data <= minVal)
        return false;

    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}
bool isValidBST(Node *root)
{
    return isValidBST(root, LONG_MIN, LONG_MAX);
    /*  TC-O(n) SC-O(h) */
}