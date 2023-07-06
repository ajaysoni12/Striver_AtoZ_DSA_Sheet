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

/*  method 1 (store inorder-traverse-find just greater than key)
    TC-O(n + log(n) or n) SC-O(n) */

/*  method 2 (traverse-find just greater than key-return)
    /*  TC-O(n) SC-O(h) */

/* method 3 */

Node *inorderSuccBST(Node *root, Node *p)
{
    Node *succ = NULL;

    while (root != NULL)
    {
        if (p->data >= root->data)
            root = root->right;
        else
        {
            succ = root;
            root = root->left;
        }
    }
    return succ;
    /*  TC-o(h or log2(n)) SC-O(1) */
}