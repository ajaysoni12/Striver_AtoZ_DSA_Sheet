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

/* method 1 (brute force approach: using every time 1 rotation) */
Node *reverseListByK(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    while (k)
    {
        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        Node *temp = head;
        tail->next = head;
        head = head->next;
        temp->next = NULL;
        k--;
    }
    return head;
    /*  TC-O(K*n)
        SC-O(1) */
}

/* method 2 (optimize approach: using single pass) */
Node *rotateListByK(Node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    Node *curr = head;
    int len = 1;
    while (curr->next != NULL && ++len)
    {
        curr = curr->next;
    }

    // make circular list
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
    /*  TC-O(n + (n - n%k))
        SC-O(1) */
}