#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int findBurnTime(unordered_map<Node *, Node *> &par_map, Node *target)
{
    queue<Node *> q;
    q.push(target);

    unordered_map<Node *, bool> vis;
    vis[target] = true;
    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;

        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                flag = 1;
                vis[node->left] = true;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                flag = 1;
                vis[node->right] = true;
                q.push(node->right);
            }
            if (par_map[node] && !vis[par_map[node]])
            {
                flag = 1;
                vis[par_map[node]] = true;
                q.push(par_map[node]);
            }
        }
        if (flag)
            time++;
    }
    return time;
}

Node *bfsParentMap(Node *root, unordered_map<Node *, Node *> &parent_map, int start)
{
    queue<Node *> q;
    q.push(root);

    Node *res;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->data == start)
            res = temp;

        if (temp->left)
        {
            parent_map[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            parent_map[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}

int timeToBurnTree(Node *root, int start)
{
    unordered_map<Node *, Node *> parent_mp;
    Node *target = bfsParentMap(root, parent_mp, start);

    return findBurnTime(parent_mp, target);
    /*  TC-O(n + n = 2n)
        SC-O(n - assuming map work in o(1) )*/
}