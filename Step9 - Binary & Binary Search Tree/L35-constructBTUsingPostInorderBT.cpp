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

Node *help(vector<int> &post, int postStart, int postEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &mp)
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    Node *root = new Node(post[postEnd]);

    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = help(post, postStart, postStart + numsLeft - 1, in, inStart, inRoot - 1, mp);
    root->right = help(post, postStart + numsLeft, postEnd - 1, in, inRoot + 1, inEnd, mp);

    return root;
}
Node *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    map<int, int> mp; // hash inorder, node data -> index
    for (int i = 0; i < inorder.size(); ++i)
        mp[inorder[i]] = i;

    Node *root = help(postorder, 0, postorder.size() - 1,
                      inorder, 0, inorder.size() - 1, mp);
    return root;
    /*  TC-O(n * nLogn - map)
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
Node *helper(int post[], int postStart, int postEnd,
             int in[], int inStart, int inEnd)
{

    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    Node *root = new Node(post[postEnd]);

    int inRoot = find_position(in, root->data, inStart, inEnd);
    int numsLeft = inRoot - inStart;

    root->left = helper(post, postStart, postStart + numsLeft - 1, in, inStart, inRoot - 1);
    root->right = helper(post, postStart + numsLeft, postEnd - 1, in, inRoot + 1, inEnd);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    Node *root = helper(post, 0, n - 1, in, 0, n - 1);
    return root;
    /*  TC-O(n * n = n^2)
        SC-O(n) */
}