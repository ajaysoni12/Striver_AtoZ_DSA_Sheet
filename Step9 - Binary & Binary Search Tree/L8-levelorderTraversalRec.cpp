#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> levelorderTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            ans.push_back(temp->data);
        }
    }

    return ans;
    /*  TC-O(n)
        SC-O(n) */
};

// level order line by line
vector<vector<int>> levelOrder(Node *node)
{
    vector<vector<int>> ans;

    if (node == NULL)
        return ans;

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> curr;
        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            curr.push_back(temp->data);
        }
        ans.push_back(curr);
    }
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}
