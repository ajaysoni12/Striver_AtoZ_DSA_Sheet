#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void makeParent(Node *root, unordered_map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parent_track; // node->parent
    makeParent(root, parent_track);

    unordered_map<Node *, bool> vist;
    queue<Node *> q;
    q.push(target);
    vist[target] = true;
    int curr_dist = 0;

    // BFS, go upto k distance
    while (!q.empty())
    {
        int size = q.size();
        if (curr_dist == k)
            break;
        curr_dist++;

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left && !vist[curr->left])
            {
                q.push(curr->left);
                vist[curr->left] = true;
            }
            if (curr->right && !vist[curr->right])
            {
                q.push(curr->right);
                vist[curr->right] = true;
            }
            if (parent_track[curr] && !vist[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                vist[parent_track[curr]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        result.push_back(curr->data);
    }

    return result;

    /*  TC-O(n + n = 2n)
        SC-O(n + n + n + n = 4n) */
}