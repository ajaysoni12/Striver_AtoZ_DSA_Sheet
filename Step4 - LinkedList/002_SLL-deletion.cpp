#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (using recurion) */
Node *deleteNode(Node *head, int x)
{
    if (!head)
        return NULL;
    if (x == 1)
        return head->next;
    head->next = deleteNode(head->next, x - 1);
    return head;
}

/* method 2 (using loop) */
Node *deleteNode(Node *head, int x)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    if (x == 1)
    {
        head = head->next;
        return head;
    }

    int count = 1;
    while (count < x - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *next = temp->next;
    temp->next = temp->next->next;
    delete next;
    return head;
}