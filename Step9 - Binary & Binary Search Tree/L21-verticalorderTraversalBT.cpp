#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<vector<int>> verticalTraversal(Node *root)
{
    // vertical, level, node
    map<int, map<int, multiset<int>>> nodes;

    // node, vertical, level
    queue<pair<Node *, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto it = todo.front();
        todo.pop();

        Node *temp = it.first;
        int v_or = it.second.first;
        int level = it.second.second;

        nodes[v_or][level].insert(temp->data);
        if (temp->left)
            todo.push({temp->left, {v_or - 1, level + 1}});
        if (temp->right)
            todo.push({temp->right, {v_or + 1, level + 1}});
    }

    vector<vector<int>> ans;
    for (auto it : nodes)
    {
        vector<int> col;
        for (auto q : it.second)
            col.insert(col.end(), q.second.begin(), q.second.end());
        ans.push_back(col);
    }
    return ans;
}