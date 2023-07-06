#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/* method 1 (optimize approach: merge two list) */
Node *mergeList(Node *first, Node *second)
{
    Node *temp = new Node(0);
    Node *curr = temp;

    while (first && second)
    {
        if (first->data <= second->data)
        {
            curr->bottom = first;
            first = first->bottom;
        }
        else
        {
            curr->bottom = second;
            second = second->bottom;
        }
        curr = curr->bottom;
    }

    curr->bottom = first ? first : second;
    return temp->bottom;
}
Node *flattenList(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flattenList(root->next);
    root = mergeList(root, root->next);
    return root;
    /*  TC-O(n*min(n1, n2))
        SC-O(n) */
}
