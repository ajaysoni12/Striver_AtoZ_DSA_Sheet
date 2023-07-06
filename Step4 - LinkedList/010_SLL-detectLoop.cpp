#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

/* method 1 (brute force approach: using hashing/set) */
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    unordered_map<Node *, int> mp;
    Node *curr = head;
    while (curr != NULL)
    {
        if (mp.find(curr) != mp.end())
            return false;
        mp[curr]++;
        curr = curr->next;
    }
    return true;
    /*  TC-O(n)
        SC-O(n) */
}

/* method 2 (optimize approach: using slow, fast pointer) */
bool detectLoop(Node *head)
{
    if (head == NULL or head->next == NULL)
        return false;
    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
    /*  TC-O(n)
        SC-O(1) */
}