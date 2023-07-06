#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void addNode(Node *head, int pos, int data)
{
    if (!head)
        return;

    Node *curr = head;
    while (pos--)
        curr = curr->next;

    Node *n = new Node(data);
    n->prev = curr;
    n->next = curr->next;
    curr->next = n;

    // need to check for last node
    if (n->next)
        n->next->prev = n;
}