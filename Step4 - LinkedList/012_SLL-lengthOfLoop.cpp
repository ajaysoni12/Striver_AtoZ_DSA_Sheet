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
int lengthOfLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    unordered_map<Node *, int> mp;
    Node *curr = head;
    int cnt = 0;
    while (curr != NULL)
    {
        // cycle found
        if (mp.find(curr) != mp.end())
        {
            // erase nodes who not a part of loop
            Node *entry = head;
            while (entry != curr)
            {
                cnt--;
                entry = entry->next;
            }
            return cnt;
        }

        // count nodes
        cnt++;
        mp[curr] = cnt;
        curr = curr->next;
    }
    return 0;
    /*  TC-O(n + n-cnt = 2n-near about)
        SC-O(n) */
}

/* method 2 (optimize solution1: using point of linkedlist) */
int lengthOfLoop(Node *head)
{
    /*
        Steps:
            1) find cycle
            2) find point of cycle
            3) count nodes in cycle
    */
    if (head == NULL || head->next == NULL)
        return 0;
    if (head->next == head)
        return 1;

    Node *slow = head;
    Node *fast = head;
    Node *entry = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // there is cycle
        {
            // found point of cycle
            while (entry != slow)
            {
                slow = slow->next;
                entry = entry->next;
            }
            int cnt = 1;
            entry = entry->next;
            while (entry != slow)
            {
                cnt++;
                entry = entry->next;
            }
            return cnt;
        }
    }
    return 0;
    /*  TC-O(n-near about + n + n = 3n-near about)
        SC-O(1) */
}

/* method 3 (otpimize solution2 : using slow and fast pointer) */
int lengthOfLoop(Node *head)
{
    /*
        Steps:
            1) find cycle
            2) count nodes in cycle
    */
    if (head == NULL || head->next == NULL)
        return 0;
    if (head->next == head)
        return 1;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // there is cycle
        {
            // count total nodes in cycle
            int cnt = 1;
            while (slow->next != fast)
            {
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }
    return 0;
    /*  TC-O(n-near about + n = 2n-near about)
        SC-O(1) */
}
