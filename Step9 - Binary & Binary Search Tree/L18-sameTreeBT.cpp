#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool sameTree(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
        return (root1 == root2);

    return (root1->data == root2->data) && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
    /*  TC-O(n)
        SC-O(n-worst case) */
}