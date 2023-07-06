#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> getInorder(Node *root)
{
    vector<int> inorder;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // first time visit-link
            // second time viist-unlink
            Node *prev = curr->left;

            // find right most guy
            while (prev->right && prev->right != curr)
                prev = prev->right;

            // link
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // unlink
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
    /*  TC-O(n) SC-O(1) */
}

vector<int> getPreorder(Node *root)
{
    vector<int> preorder;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // first time visit-link
            // second time viist-unlink
            Node *prev = curr->left;

            // find right most guy
            while (prev->right && prev->right != curr)
                prev = prev->right;

            // link
            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->data); // root left right
                curr = curr->left;
            }
            // unlink
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
    /*  TC-O(n + n-whileloop = 2n-near about) SC-O(1) */
}