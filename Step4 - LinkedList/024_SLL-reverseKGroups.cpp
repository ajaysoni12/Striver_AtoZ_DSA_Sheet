#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

/* method 1 (brute force approach: using recursion) */
node *reverse(node *head, int k)
{
    int count = 0;
    node *prev = NULL, *next = NULL;
    node *curr = head;
    while (curr != NULL and count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        curr->next = reverse(next, k);
    return prev;
    /*  TC-O(n)
        SC-O(k) */
}

/* method 2 (optimize approach: )*/
int lengthOfLinkedList(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        ++length;
        head = head->next;
    }
    return length;
}
node *reverseKNodes(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int length = lengthOfLinkedList(head);

    node *dummyHead = new node(0);
    dummyHead->next = head;

    node *pre = dummyHead;
    node *cur;
    node *nex;

    while (length >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}