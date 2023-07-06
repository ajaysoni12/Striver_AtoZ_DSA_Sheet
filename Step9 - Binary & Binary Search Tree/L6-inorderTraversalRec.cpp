#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorderTravsal(struct node *root)
{
    if (root == NULL)
        return;

    /*  (Left, Root, Right)  */
    inorderTravsal(root->left);
    cout << root->data << " ";
    inorderTravsal(root->right);

    /*  TC-O(n)
        SC-O(h or n(squeed tree)) */
}