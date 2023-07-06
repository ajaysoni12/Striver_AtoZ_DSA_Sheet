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

Node *findLastRight(Node *root)
{
    if (root->right == NULL)
        return root;
    return findLastRight(root->right);
}
Node *help(Node *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;

    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return help(root);

    Node *dummy = root;
    while (root != NULL)
    {
        // go to the left
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = help(root->left);
                break;
            }
            else
                root = root->left;
        }
        // go to the right
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = help(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
    /*  TC-O(height of BST) SC-O(1) */
}