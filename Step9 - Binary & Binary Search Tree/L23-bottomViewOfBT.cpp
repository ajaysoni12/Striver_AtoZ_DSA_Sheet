#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* can i use recursion traversal, ans is no
Why? reson is if left right visit first time but in real it's not a part of
top view, you need to introduce height also(min) */

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // line, data
    map<int, int> mp;

    // node, line
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int line = it.second;

        mp[line] = node->data;

        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
    /*  TC-O(n)
        SC-O(2n) */
}