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

/* method 1 (brute force approach: using two loops) */
Node *findIntersection(Node *head1, Node *head2)
{
    Node *newHead = new Node(-1);
    Node *curr_pos = newHead;

    Node *curr = head1;
    while (curr != NULL)
    {
        Node *temp = head2;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                Node *n = new Node(curr->data);
                curr_pos->next = n;
                curr_pos = n;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
    return newHead->next;
    /*  TC-O(n1*n2)
        SC-O(1) */
}

/* method 2 (optimize approach: using hashing) */
Node *findIntersection(Node *head1, Node *head2)
{
    // common element
    unordered_set<int> set;

    // push all element in set of head2 list, according to question
    Node *curr = head2;
    while (curr != NULL)
    {
        set.insert(curr->data);
        curr = curr->next;
    }

    Node *newHead = new Node(-1);
    Node *curr_pos = newHead;

    curr = head1;
    while (curr != NULL)
    {
        if (set.find(curr->data) != set.end())
        {
            Node *n = new Node(-1);
            curr_pos->next = n;
            curr_pos = n;
        }
        curr = curr->next;
    }
    return newHead->next;
    /*  TC-O(n1 + n2) 
        SC-O(n2) */
}