#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* using recursion */
Node *searchBST(Node *root, int val)
{
    if (root == NULL || root->data == val)
        return root;
    return val < root->data ? searchBST(root->left, val) : searchBST(root->right, val);
    /*  TC-O(log2(n)) SC-O(h) */
}

/* using iterative */
Node *searchBST(Node *root, int val)
{
    while (root != NULL && root->data != val)
        root = val < root->data ? root->left : root->right;

    return root;
    /*  TC-O(log2(n)-near about) SC-O(1) */
}
