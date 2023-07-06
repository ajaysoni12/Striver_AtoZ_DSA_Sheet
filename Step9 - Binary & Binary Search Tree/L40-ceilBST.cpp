#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int ceilBST(Node *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        else if (key > root->data)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
    /*  TC-O(log2(n)) SC-O(1) */
}