#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* method 1 - mainly create bst, TC-O(n * n(sqwed tree) = n^2) SC-O(1) */
/* method 2 - convert into inorder, using preorder, construct BST - o(nLog(n) + n) */

Node *build(vector<int> &arr, int &ind, int bound)
{
    if (ind == arr.size() || arr[ind] > bound)
        return NULL;

    Node *root = new Node(arr[ind++]);        // also update index
    root->left = build(arr, ind, root->data); // update bound
    root->right = build(arr, ind, bound);     // bound remain same
}
Node *bstFormPreorder(vector<int> &arr)
{
    int ind = 0;
    return build(arr, ind, INT_MAX);
    // you visit single node 3 times
    /*  TC-O(3n = n) SC-O(h) */
}
