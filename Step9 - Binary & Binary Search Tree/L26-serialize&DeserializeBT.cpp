#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> serialize(Node *root)
{
    vector<int> arr;
    if (root == NULL)
        return arr;

    // apply level order traverse, you can apply any traversal
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();

        if (curr_node == NULL)
            arr.push_back(-1);
        else
            arr.push_back(curr_node->data);

        if (curr_node != NULL)
        {
            q.push(curr_node->left);
            q.push(curr_node->right);
        }
    }
    return arr;
    /*  TC-O(n) SC-O(n) */
}

Node *de_serialize(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    Node *root = new Node(arr[0]);
    int index = 1;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();

        int val = arr[index++];
        if (val == -1)
            curr_node->left = NULL;
        else
        {
            Node *temp = new Node(val);
            curr_node->left = temp;
            q.push(temp);
        }

        val = arr[index++];
        if (val == -1)
            curr_node->right = NULL;
        else
        {
            Node *temp = new Node(val);
            curr_node->right = temp;
            q.push(temp);
        }
    }
    return root;
    /*  TC-O(n) SC-O(n) */
}