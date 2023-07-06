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
/*  method 1 (brute force approach: using extra space or list)
    TC-O(n + n = 2n)
    SC-O(n) */

/* method 2 (optimal approach: using modification) */
Node *segregateEvenOdd(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *even = new Node(-1);
    Node *odd = new Node(-1);
    Node *curr_even = even;
    Node *curr_odd = odd;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            curr_even->next = temp;
            curr_even = temp;
        }
        else
        {
            curr_odd->next = temp;
            curr_odd = temp;
        }
        temp = temp->next;
    }
    curr_odd->next = nullptr;
    curr_even->next = odd->next;
    return even->next;
    /*  TC-O(n)
        SC-O(1) 
    */
}