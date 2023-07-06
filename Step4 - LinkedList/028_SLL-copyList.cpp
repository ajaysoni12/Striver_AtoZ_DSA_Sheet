#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int data)
    {
        next = arb = NULL;
    }
};
Node *copyList(Node *head)
{
    Node *temp = head;
    Node *newHead;

    unordered_map<Node *, Node *> mp;

    newHead = new Node(temp->data);
    mp[temp] = newHead;

    while (temp->next != nullptr)
    {
        newHead->next = new Node(temp->next->data);
        temp = temp->next;
        newHead = newHead->next;
        mp[temp] = newHead;
    }

    temp = head;
    while (temp != nullptr)
    {
        mp[temp]->arb = mp[temp->arb];
        temp = temp->next;
    }

    return mp[head];
}
