#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int _data)
    {
        data = _data;
        left = right = NULL;
    }
};

Node *help(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &mp)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node *root = new Node(pre[preStart]);

    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = help(pre, preStart + 1, preStart + numsLeft, in, inStart, inRoot - 1, mp);
    root->right = help(pre, preStart + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, mp);

    return root;
}
Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp; // hash inorder, node data -> index
    for (int i = 0; i < inorder.size(); ++i)
        mp[inorder[i]] = i;

    Node *root = help(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1, mp);
    return root;
    /*  TC-O(n * nLogn)
        SC-O(n) */
}

/* for duplicate element */
int find_position(int in[], int &ele, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == ele)
            return i;
    }
    return -1;
}
Node *helper(int pre[], int preStart, int preEnd,
             int in[], int inStart, int inEnd)
{

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node *root = new Node(pre[preStart]);

    int inRoot = find_position(in, root->data, inStart, inEnd);
    int numsLeft = inRoot - inStart;

    root->left = helper(pre, preStart + 1, preStart + numsLeft,
                        in, inStart, inRoot - 1);

    root->right = helper(pre, preStart + numsLeft + 1, preEnd,
                         in, inRoot + 1, inEnd);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    Node *root = helper(pre, 0, n - 1, in, 0, n - 1);
    return root;
    /*  TC-O(n * n = n^2)
        SC-O(n) */
}