#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    if (not head)
    {
        return head;
    }
    if (not head->next)
    {
        head->prev = NULL;
        return head;
    }

    Node *newHead = reverseDLL(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    return newHead;
}

Node *reverseDLL(Node *head)
{
    if (!head or !head->next)
        return head;

    Node *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        head->prev = next;
        prev = head;
        head = next;
    }
    return prev;
}