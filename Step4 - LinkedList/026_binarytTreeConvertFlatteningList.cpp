#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* method 1 (brute force appraoch: recursion/stack) */
Node *prev = NULL;
void flattenList(Node *root)
{
    if (root == NULL)
        return;

    flattenList(root->right);
    flattenList(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
    /*  TC-O(n)
        SC-O(n) */

    /*
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            curr = st.top();
            st.pop();

            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);

            if(!st.empty()) {
                curr->right = st.top();
            }

            curr->left = NULL;
        }
        TC-O(n)
        SC-O(n)
    */
}

/* method 2 (optimize approach: without extra space) */
void flattenList(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left)
        {
            Node *prev = curr->left;
            while (prev->right)
                prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    /*  TC-O(n)
        SC-O(1) */
}