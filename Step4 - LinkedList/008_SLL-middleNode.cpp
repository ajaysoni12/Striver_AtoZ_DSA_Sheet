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

/* method 1 (brute force approach: linear traversal) */
Node *getMiddle(Node *head)
{
    if (head == NULL)
        return NULL;
    int len = 0;
    Node *curr = head;

    // count len of linked-list
    while (curr != NULL)
        curr = curr->next, len++;

    // valid for odd and even length
    int middleNode = (len / 2) + 1;

    // reach out middle node
    curr = head;
    while (curr != NULL)
    {
        middleNode--;
        if (middleNode == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
    /*  TC-O(n + n/2)
        SC-O(1) */
}

/* method 2 (optimize approach: tortoise(slow, fast) method) */
Node *getMiddle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
        slow = slow->next, fast = fast->next->next;

    return slow; // if you need to return first, then store prev
    /*  TC-O(n/2)
        SC-O(1) */
}