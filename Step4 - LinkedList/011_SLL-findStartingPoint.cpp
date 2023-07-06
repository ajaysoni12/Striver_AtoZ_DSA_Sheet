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

/* method 1 (brute force approach: using hashing) */
Node *findStartingPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL; // -1

    if (head->next == head)
        return head;

    Node *curr = head;
    unordered_map<Node *, int> mp;
    while (curr != NULL)
    {
        if (mp.find(curr) != mp.end())
            return curr;
        mp[curr]++;
        curr = curr->next;
    }
    return NULL;
    /*  TC-O(n)
        SC-O(n) */
}

/* method 2 (optimize approach: using slow and fast pointer) */
Node *findStartingPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL; // -1

    if (head->next == head)
        return head;

    Node *slow = head, *fast = head, *entry = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // there is a cycle
        {
            while (slow != entry) // found entry node
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
    /*
        2(l1 + l2) = l1 + l2 + nC, n-turns, C-cycle length
        l1 = l2 - nC
    */
    /*   TC-O(n - near about)
         SC-O(1)
     */
}