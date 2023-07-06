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

/*  method 1 (brute force approach)
    Steps:
        1) count length of list
        2) find middle
        3) store prev node in extra pointer
        4) delete nodes

    TC-O(n + n/2)
    SC-O(1)
*/

/* method 2 (optimize approach: using slow fast pointer) */
Node *deleteMiddleNode(Node *head)
{
    if (!head || !head->next)
        return NULL;

    // find middle node
    Node *slow = head, *fast = head;
    Node *prev = NULL;
    while (fast != NULL and fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head; 
    /*  TC-O(n/2)
        SC-O(1) */
}