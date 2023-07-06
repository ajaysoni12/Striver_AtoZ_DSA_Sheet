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

/*  method 1 (brute force appraoach: using bubble sort) */
Node *sort012(Node **head)
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

/* method 2 (better approach: cnt 0, 1, 2) */
Node *sort012(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            cnt0++;
        else if (curr->data == 1)
            cnt1++;
        else
            cnt2++;
    }

    curr = head;
    while (curr != NULL)
    {
        if (cnt0 > 0)
            curr->data = 0, cnt0--;
        else if (cnt1 > 0)
            curr->data = 1, cnt1--;
        else
            curr->data = 2, cnt2--;

        curr = curr->next;
    }
    return head;
    /*  TC-O(n + n = 2n)
        SC-O(1) */
}

/* method 3 (optimize approach: single pass) */
Node *sort012(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *cnt0 = new Node(-1);
    Node *curr_0 = cnt0;

    Node *cnt1 = new Node(-1);
    Node *curr_1 = cnt1;

    Node *cnt2 = new Node(-1);
    Node *curr_2 = cnt2;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            curr_0->next = curr, curr_0 = curr;
        else if (curr->data == 1)
            curr_1->next = curr, curr_1 = curr;
        else
            curr_2->next = curr, curr_2 = curr;

        curr = curr->next;
    }

    if (cnt1->next)
    {
        curr_0->next = cnt1->next;
        curr_1->next = cnt2->next;
    }
    else
        curr_0->next = cnt2->next;

    curr_2->next = NULL;
    return cnt0->next;
    /*  TC-O(n)
        SC-O(1) */
}