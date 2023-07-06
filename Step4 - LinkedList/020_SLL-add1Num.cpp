#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

/* method 1 (brute force approach: generate no., +1, and push again) */
Node *reverseList(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *prev = NULL, *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
Node *add1Num(Node *head)
{
    // reverse list
    head = reverseList(head);

    int carry = 0;
    Node *curr = head;
    Node *prev = NULL; // store prev node address
    while (curr != NULL)
    {
        int sum = curr->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        curr->data = rem;
        prev = curr;
        curr = curr->next;
    }
    if (carry > 0)
        prev->next = new Node(carry);

    head = reverseList(head);
    return head->next;
    /*  TC-O(n + n + n = 3n)
        SC-O(1) */
}