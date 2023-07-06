#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        // first go the left
        if (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            // if stack empty means not need of traverse
            if (st.empty() == true)
                break;
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
    /*  TC-O(n)
        SC-O(n or h-height of tree) */
}