#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
vector<int> postorderTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left)
            st1.push(root->left);
        if (root->right)
            st2.push(root->right);
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
    /*  TC-O(n)
        SC-O(n + n = 2n) */
}

/* using single stack */
vector<int> postorderTraversal(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    return ans;
    /*  TC-O(2n - in worst case, all tree have only right nodes)
        SC-O(n) */
}