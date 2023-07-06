#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* using recursion */
Node *lcaOfBST(Node *root, Node *p, Node *q)
{
    // root is empty
    if (root == NULL)
        return root;
    int curr = root->data;

    // both lies on the right side
    if (curr < p->data && curr < q->data)
        return lcaOfBST(root->right, p, q);

    // both lies on the left side
    if (curr > p->data && curr > q->data)
        return lcaOfBST(root->left, p, q);

    // otherwise, this my lca
    return root;

    /*  TC-O(h) SC-O(h) */
}

/* using iterative way */
Node *lcaOfBST(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data < p->data && curr->data < q->data)
            curr = curr->right;
        else if (curr->data > p->data && curr->data > q->data)
            curr = curr->left;
        else
            return curr;
    }
    return NULL;
    /*  TC-O(h) SC-O(1) */
}