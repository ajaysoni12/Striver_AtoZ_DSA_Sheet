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
    Steps:
        1) copy ele into array
        2) sort the array
        3) again copy ele
    TC-O(n + nLogn + n)
    SC-O(n)
*/

/* metod 2 (better approach: using sorting algo) */
Node *sortList(Node **head)
{
    Node *n1 = *head;
    Node *n2 = n1->next;

    while (n2 != NULL || n1->next != NULL)
    {
        if (n1->data > n2->data)
        {
            int t = n1->data;
            n1->data = n2->data;
            n2->data = t;
        }
        n2 = n2->next;
        if (n2 == NULL)
        {
            n1 = n1->next;
            n2 = n1->next;
        }
    }
    return *head;
    /*  TC-O(n*n = n^2 -near about)
        SC-O(1) */
}

/* method 2 (optimize approach: using modification) */
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
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
Node *mergeList(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data <= l2->data)
    {
        l1->next = mergeList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeList(l1, l2->next);
        return l2;
    }
}
Node *sortList(Node **head)
{
    Node *curr = *head;
    if (curr == NULL || curr->next == NULL)
        return;

    Node *list1 = new Node(-1);
    Node *list2 = new Node(-1);
    Node *curr_list1 = list1;
    Node *curr_list2 = list2;

    // divide into lists
    // Node curr = *head;
    while (curr != NULL)
    {
        curr_list1->next = curr;
        curr_list1 = curr;
        curr = curr->next;
        if (curr == NULL)
            break;
        curr_list2->next = curr;
        curr_list2 = curr;
        curr = curr->next;
    }

    curr_list2->next = NULL;
    curr_list1->next = NULL;

    // reverse laset list
    list2->next = reverseList(list2->next);

    // merge both list
    *head = mergeList(list1->next, list2->next);
    /*  TC-O(n + n + n = 3n)
        SC-O(1) */
}