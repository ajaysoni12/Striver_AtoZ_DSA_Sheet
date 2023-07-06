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

/* method 1 (brute force approach: using extra space) */
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    vector<int> temp;
    Node *curr = head;
    while (curr != NULL)
    {
        temp.push_back(curr->data);
        curr = curr->next;
    }

    int low = 0, high = temp.size() - 1;
    while (low < high)
    {
        if (temp[low] != temp[high])
            return false;
        low++, high--;
    }
    return true;
    /*  TC-O(n + n = 2n)
        SC-O(n) */
}

/* method 2 (optimize approach: find middle and reverse remaning list) */
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
bool isPalindrome(Node *head)
{
    /*
        Steps:
            1) find middle node
            2) reverse half list
            3) compare
    */
    if (head == NULL || head->next == NULL)
        return true;

    // find middle node of list
    Node *slow = head, *fast = head;
    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse right half list
    slow->next = reverseList(slow->next);

    // check left half and right half equal or ot
    Node *list1 = head;
    Node *list2 = slow->next; // take right of list
    while (list1 != NULL and list2 != NULL)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return true;
    /*  TC-O(n/2 + n/2 + n/2 + (n/2 + n/2 - option, back origanl list))
        SC-O(1) */
}