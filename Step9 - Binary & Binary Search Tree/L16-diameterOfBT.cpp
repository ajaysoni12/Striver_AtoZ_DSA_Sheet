#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

/* longest path from every node, and it will contain root, or without root */
void diameterOfBT(Node *root, int &maxDia)
{
    if (root == NULL)
        return;

    int lh = 0;
    lh = height(root->left);
    int rh = 0;
    rh = height(root->right);

    maxDia = max(maxDia, lh + rh);
    diameterOfBT(root->left, maxDia);
    diameterOfBT(root->right, maxDia);
    /*  TC-O(n(traversal) * n(find height) = n^2)
        SC-O(n-worst case) */
}

int diamterOfBT(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = diamterOfBT(root->left, maxi);
    int rh = diamterOfBT(root->right, maxi);

    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);
    /*  TC-O(n)
        SC-O(n-for squeed tree) */
}