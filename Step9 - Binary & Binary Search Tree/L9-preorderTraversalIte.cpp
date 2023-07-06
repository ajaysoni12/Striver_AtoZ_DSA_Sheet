#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> preorderTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        // first push right node
        if (root->right)
            st.push(root);

        // then push left node
        if (root->left)
            st.push(root);

        ans.push_back(root->data);
    }
    return ans;
    /*  TC-O(n)
        SC-O(n or h-height of binary tree) */
}