#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int getCount(struct Node *head)
{
    Node *curr = head;
    int cnt = 0;
    while (curr != NULL)
        curr = curr->next, cnt++;
    return cnt;
}