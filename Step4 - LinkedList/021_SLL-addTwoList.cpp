#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/*  method 1 (brute force approach: using extra space or list)
    TC-O(n1 + n2)
    SC-O(n1 + n2)
*/

/* method 2 (optimize approach: using some modification) */
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
Node *addTwoList(Node *head1, Node *head2)
{

    if (head1 == NULL or head2 == NULL)
        return NULL;

    head1 = reverseList(head1);
    head2 = reverseList(head2);

    Node *newHead = new Node(-1);
    Node *curr_list = newHead;

    int carry = 0;
    Node *list1 = head1, *list2 = head2;

    while (list1 and list2)
    {
        int sum = list1->data + list2->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        curr_list->next = new Node(rem);
        curr_list = curr_list->next;

        list1 = list1->next;
        list2 = list2->next;
    }

    // if one list is empty
    Node *remainList = list1 == NULL ? list2 : list1;
    while (remainList)
    {
        int sum = remainList->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        curr_list->next = new Node(rem);
        curr_list = curr_list->next;

        remainList = remainList->next;
    }

    if (carry > 0)
    {
        curr_list->next = new Node(carry);
        curr_list = curr_list->next;
    }
    newHead->next = reverseList(newHead->next);
    return newHead->next;
    /*  TC-O(n1 + n2 + max(n1, n2))
        SC-O(max(n1, n2)) */
}