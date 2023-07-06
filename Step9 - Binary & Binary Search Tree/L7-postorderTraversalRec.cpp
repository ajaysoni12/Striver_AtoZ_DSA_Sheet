#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorderTravsal(struct node *root)
{
    if (root == NULL)
        return;

    /*  (Root, Left, Right)  */
    preorderTravsal(root->left);
    preorderTravsal(root->right);
    cout << root->data << " ";

    /*  TC-O(n)
        SC-O(h or n(squeed tree)) */
}