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

/*  method 1 (brute force approach: using extra space)
    TC-O(n)
    SC-O(n)
*/

/* method 2 (optimize approach: cnt list size + and find) */
int getNthFromLast(Node *head, int n)
{
    int len = 0;

    Node *curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    int steps = len - n;
    if (steps < 0)
        return -1;

    curr = head;
    while (steps > 0)
    {
        curr = curr->next;
        steps--;
    }
    return curr->data;
    /*  TC-O(n + n = 2n)
        SC-O(1) */
}

/* method 3 (most optimize method: single traverse) */
int getNthFromLast(Node *head, int n)
{
    Node *curr = head;
    Node *save = head;

    while (curr != NULL)
    {
        if (n)
            n--;
        else
            save = save->next;
        curr = curr->next;
    }

    if (n)
        return -1;
    return save->data;
    /*  TC-O(n)
        SC-O(1) */
}