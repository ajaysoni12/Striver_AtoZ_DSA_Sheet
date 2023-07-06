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

/*  method 1 - store any traversal-sort-again traverse and repalce valued
    TC-O(n + n + nLogn = 2n + nLogn) SC-O(n + h) */

class Solution
{
private:
    Node *first;
    Node *last;
    Node *prev, *middle;

public:
    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && (root->data < prev->data))
        {

            // if this is a first vilaton, mark these two nodes as
            // first and middle
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // second vialation
            else
            {
                last = root;
            }
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }
    void correctBST(struct Node *root)
    {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);

        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
    /*  TC-O(n) SC-O(h or 1) */
};