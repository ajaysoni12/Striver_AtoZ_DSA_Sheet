#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    bool leftToRight = true;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(row);
    }
    return ans;
    /*  TC-O(n)
        SC-O(n) */
}