#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<vector<int>> pre_in_postInSingleTraverse(Node *root)
{
    stack<pair<Node *, int>> st;
    vector<int> pre, in, post;
    st.push({root, 1});

    if (root == NULL)
        return {pre, in, post};

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is a part of pre
        // incremenet 1 to 2
        // push the left side of tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }

        // this is part of in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }

        // don't push it, just back
        else
            post.push_back(it.first->data);
    }

    return {pre, in, post};

    /*  TC-O(3n)
        SC-O(4n) */
}