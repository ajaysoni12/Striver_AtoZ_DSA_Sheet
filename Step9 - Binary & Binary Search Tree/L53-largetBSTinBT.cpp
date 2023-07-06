#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/*  method 1 - (go to every node-check valid bst-if get true, then again    apply any traversal for counting nodes)
    TC-O(n * n = n^2) SC-O(1) */

/* method 2 () */
class NodeValue
{
public:
    int maxNode, minNode, size;
    NodeValue(int mxN, int mnN, int sz)
    {
        maxNode = mxN;
        minNode = mnN;
        size = sz;
    }
};

class Solution
{
private:
    NodeValue largestBSTSubtreeHelper(Node *root)
    {
        // if it is en empty BST of size 0
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // Get value from left and right subtree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // if curr node data is greater than left max, &
        // smaller than in min of right,
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            // it is a bst
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.size + right.size + 1);
        }

        // otherwise, return [-inf, inf] so that prenet can't be vallid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }

public:
    int largestBSTSubtree(Node *root)
    {
        return largestBSTSubtreeHelper(root).size;
        /*  TC-O(n) SC-O(1) */
    }
};