#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int findLeftHeight(Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}
int findRightHeight(Node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1; // total nodes
    return 1 + countNodes(root->left) + countNodes(root->right);

    /*  TC-O(log(n) - in left side, i will go  * log(n) - compute height = log(n)^2)
        ASC-O(h) */
}