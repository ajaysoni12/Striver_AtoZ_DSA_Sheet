#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

/*  method 1 (brute force approach: using extra space)
    Steps:
        1) decleare vector
        2) traverse list and push element
        3) reverse vector
        4) again push ele
        5) get reverse list

        TC-O(n + n + n = 3n)
        SC-O(n)
*/

/* method 2 (optimize approach(iterative): using three pointer) */
Node *reverseList(Node *head)
{
    // pointer cofrugation, break the link & joine with reverse node
    Node *prev = NULL, *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev; // head of the linked list
    /*  TC-O(n)
        SC-O(1) */
}

/* method 2 (optimize approach(recursive): using recursion) */
Node *reverseList(Node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;

    Node *newHead = reverseList(head->next);

    // pointer manipulation
    head->next->next = head;
    head->next = NULL;

    // always return newHead
    return newHead;
    /*  TC-O(n)
        SC-O(n - recursive stack space) */
}