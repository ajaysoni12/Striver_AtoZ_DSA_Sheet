#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool getPath(Node *root, vector<int> &ans, int x)
{
    if (root == NULL)
        return true;

    ans.push_back(root->data);

    if (root->data == x)
        return true;

    if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
    /*  TC-O(n) SC-O(n) */
}
