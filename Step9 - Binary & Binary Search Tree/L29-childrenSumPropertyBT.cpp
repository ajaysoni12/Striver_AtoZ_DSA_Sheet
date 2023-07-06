#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*  condition:  node->data == left->data + right->data
                data++, by one
*/
void changeBT(Node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    changeBT(root->left);
    changeBT(root->right);

    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left or root->right)
        root->data = total;

    /*  TC-O(n) SC-O(n) */
}