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
        next = NULL;
        prev = NULL;
    }
};

Node *deleteNode(Node *head, int x)
{
    Node *curr = head;

    // reachout node
    while (--x)
        curr = curr->next;

    // first node
    if (curr == head)
    {
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        curr->prev->next = curr->next;

        // for middle node
        if (curr->next)
            curr->next->prev = curr->prev;
    }
    delete curr;
    return head;
}