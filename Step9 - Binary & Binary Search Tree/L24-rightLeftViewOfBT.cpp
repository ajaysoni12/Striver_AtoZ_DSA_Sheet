#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*  RIGHT VIEW  */
void solve(Node *root, int level, vector<int> &ds)
{
    if (root == NULL)
        return;

    if (level == ds.size())
        ds.push_back(root->data);

    // first goto the right
    solve(root->right, level + 1, ds);
    // then goto the left
    solve(root->left, level + 1, ds);
    /*  TC-O(n) SC-O(h) */
}
vector<int> rightView(Node *root)
{
    vector<int> ds;
    solve(root, 0, ds);
    return ds;
}

/*  LEFT VIEW  */
void solve(Node *root, int level, vector<int> &ds)
{
    if (root == NULL)
        return;

    if (level == ds.size())
        ds.push_back(root->data);

    // first goto the left
    solve(root->left, level + 1, ds);
    // then goto the right
    solve(root->right, level + 1, ds);

    /*  TC-O(n) SC-O(h) */
}
vector<int> leftView(Node *root)
{
    vector<int> ds;
    solve(root, 0, ds);
    return ds;
}